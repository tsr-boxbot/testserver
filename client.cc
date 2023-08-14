#include <iomanip>
#include <iostream>
#include <memory>
#include <string>

#include <grpcpp/ext/proto_server_reflection_plugin.h>
#include <grpcpp/grpcpp.h>
#include <grpcpp/health_check_service_interface.h>

#include "proto/testserver.grpc.pb.h"

using grpc::Channel;
using grpc::ClientContext;
using grpc::Status;

class Client {
 public:
  Client(std::shared_ptr<Channel> channel) : stub_(testserver::Api::NewStub(channel)) {}

  void DoThingRequest(void)
  {
    testserver::DoThingRequest request;
    request.set_message("foobar");
    testserver::DoThingResponse response;
    ClientContext context;
    Status status = stub_->DoThing(&context, request, &response);

    if (!status.ok()) {
      std::cout << status.error_message() << std::endl;
      return;
    }
    std::cout << response.message() << std::endl;
  }

 private:
  std::unique_ptr<testserver::Api::Stub> stub_;
};

int main(int argc, char** argv) {
  Client(grpc::CreateChannel("localhost:50051", grpc::InsecureChannelCredentials())).DoThingRequest();

  return 0;
}
