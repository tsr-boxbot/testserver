#include <iomanip>
#include <iostream>
#include <memory>
#include <string>

#include <grpcpp/ext/proto_server_reflection_plugin.h>
#include <grpcpp/grpcpp.h>
#include <grpcpp/health_check_service_interface.h>

#include "protos/testserver.grpc.pb.h"

using grpc::Channel;
using grpc::ClientContext;
using grpc::Status;

class Client {
 public:
  Client(std::shared_ptr<Channel> channel) : stub_(StorageState::StorageStateAPI::NewStub(channel)) {}

  void GetTreeMetaData(void)
  {
    GetTreeMetaDataRequest request;
    request.set_tree_num(0);
    GetTreeMetaDataResponse response;
    ClientContext context;
    Status status = stub_->GetTreeMetaData(&context, request, &response);

    if (!status.ok()) {
      std::cout << status.error_message() << std::endl;
      return;
    }
    std::cout << response.data().num() << std::endl;
    std::cout << response.data().name() << std::endl;
  }

  void SetTreeMetaData(void)
  {
    SetTreeMetaDataRequest request;
    request.mutable_data()->set_num(0);
    request.mutable_data()->set_name("foobar");
    SetTreeMetaDataResponse response;
    ClientContext context;
    Status status = stub_->SetTreeMetaData(&context, request, &response);

    if (!status.ok()) {
      std::cout << status.error_message() << std::endl;
      return;
    }
  }

 private:
  std::unique_ptr<StorageState::StorageStateAPI::Stub> stub_;
};

int main(int argc, char** argv) {
  Client(grpc::CreateChannel("localhost:50051", grpc::InsecureChannelCredentials())).SetTreeMetaData();
  Client(grpc::CreateChannel("localhost:50051", grpc::InsecureChannelCredentials())).GetTreeMetaData();

  return 0;
}
