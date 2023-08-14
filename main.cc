#include <atomic>
#include <memory>
#include <mutex>
#include <thread>

#include <grpcpp/ext/proto_server_reflection_plugin.h>
#include <grpcpp/grpcpp.h>
#include <grpcpp/health_check_service_interface.h>

#include "proto/testserver.grpc.pb.h"

class Application final : public testserver::Api::Service {
 public:
  Application();
  ~Application();

  grpc::Status DoThing(grpc::ServerContext* context, const testserver::DoThingRequest* request,
                          testserver::DoThingResponse* response) override;
private:
  std::unique_ptr<grpc::Server> server_;
};

grpc::Status Application::DoThing(grpc::ServerContext* context, const testserver::DoThingRequest* request,
                          testserver::DoThingResponse* response)
{
  return grpc::Status(grpc::StatusCode::UNIMPLEMENTED, "Functionality is unimplemented");;
}

Application::~Application() { server_->Shutdown(); }

Application::Application() {
  std::string server_address("0.0.0.0:50051");

  grpc::EnableDefaultHealthCheckService(true);
  grpc::reflection::InitProtoReflectionServerBuilderPlugin();
  grpc::ServerBuilder builder;

  builder.AddListeningPort(server_address, grpc::InsecureServerCredentials());

  builder.RegisterService(this);

  std::unique_ptr<grpc::Server> local_server(builder.BuildAndStart());

  server_ = std::move(local_server);
}

int main(void)
{
  std::cout << "hello world!" << std::endl;
  return 0;
}
