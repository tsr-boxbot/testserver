#include <atomic>
#include <memory>
#include <mutex>
#include <thread>

#include "database.h"
#include <grpcpp/ext/proto_server_reflection_plugin.h>
#include <grpcpp/grpcpp.h>
#include <grpcpp/health_check_service_interface.h>
#include "paho-mqtt-cpp/include/mqtt/client.h"
#include "announcer.h"

using API = StorageState::StorageStateAPI;

class Application final : public API::Service {
 public:
  Application();
  ~Application();

  virtual grpc::Status SetTreeMetaData(grpc::ServerContext* context,
                                       const SetTreeMetaDataRequest* request,
                                       SetTreeMetaDataResponse* response) final
  {
    if(const grpc::Status status = database_->SetTreeMetaData(context, request, response); !status.ok())
      return status;
    return announcer_->GetTreeMetaData(context, request, response);
  }
  virtual grpc::Status GetTreeMetaData(grpc::ServerContext* context,
                                       const GetTreeMetaDataRequest* request,
                                       GetTreeMetaDataResponse* response) final
  {
    return database_->GetTreeMetaData(context, request, response);
  }
  void Wait() { server_->Wait(); }

 private:
  std::unique_ptr<grpc::Server> server_;
  std::unique_ptr<Database> database_;
  std::unique_ptr<Announcer> announcer_;
};

Application::~Application() { server_->Shutdown(); }

Application::Application() : database_(CreateDatabase()), announcer_(CreateAnnouncer()) {
  std::string server_address("0.0.0.0:50081");

  grpc::EnableDefaultHealthCheckService(true);
  grpc::reflection::InitProtoReflectionServerBuilderPlugin();
  grpc::ServerBuilder builder;

  builder.AddListeningPort(server_address, grpc::InsecureServerCredentials());

  builder.RegisterService(this);

  std::unique_ptr<grpc::Server> local_server(builder.BuildAndStart());

  server_ = std::move(local_server);
}

int main(void) {
  std::cout << "hello world!" << std::endl;
  Application().Wait();
  return 0;
}
