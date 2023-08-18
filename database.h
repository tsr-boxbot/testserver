
#pragma once

#include "protos/testserver.grpc.pb.h"
#include <grpcpp/ext/proto_server_reflection_plugin.h>
#include <grpcpp/grpcpp.h>
#include <grpcpp/health_check_service_interface.h>

class Database {
 public:
  virtual ~Database() {}
  virtual grpc::Status GetTreeMetaData(grpc::ServerContext* context,
                                       const GetTreeMetaDataRequest* request,
                                       GetTreeMetaDataResponse* response) = 0;

  virtual grpc::Status SetTreeMetaData(grpc::ServerContext* context,
                                       const SetTreeMetaDataRequest* request,
                                       SetTreeMetaDataResponse* response) = 0;
};

extern std::unique_ptr<Database> CreateDatabase();
