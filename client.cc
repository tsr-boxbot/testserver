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

  void GetTreeMetaData(int num)
  {
    GetTreeMetaDataRequest request;
    request.set_tree_num(num);
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

  void SetTreeMetaData(int num, std::string_view name)
  {
    SetTreeMetaDataRequest request;
    request.mutable_data()->set_num(num);
    request.mutable_data()->set_name(name.data());
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
  Client(grpc::CreateChannel("localhost:50081", grpc::InsecureChannelCredentials())).SetTreeMetaData(0, "asdf");
  Client(grpc::CreateChannel("localhost:50081", grpc::InsecureChannelCredentials())).GetTreeMetaData(0);
  Client(grpc::CreateChannel("localhost:50081", grpc::InsecureChannelCredentials())).SetTreeMetaData(1, "foobar");
  Client(grpc::CreateChannel("localhost:50081", grpc::InsecureChannelCredentials())).GetTreeMetaData(1);

  return 0;
}
