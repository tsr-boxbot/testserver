#include "database.h"

class InMemoryDatabase final : public Database {
 private:
   struct meta_data_t
   {
     std::int32_t num;
     std::string name;
   };
   std::unordered_map<std::int32_t, meta_data_t> meta_data;

 public:
  InMemoryDatabase() {}
  virtual ~InMemoryDatabase() {}
  virtual grpc::Status GetTreeMetaData(grpc::ServerContext* context,
                                       const GetTreeMetaDataRequest* request,
                                       GetTreeMetaDataResponse* response) final {
    response->mutable_data()->set_num(meta_data[request->tree_num()].num);
    response->mutable_data()->set_name(meta_data[request->tree_num()].name);
    return grpc::Status();
  }

  virtual grpc::Status SetTreeMetaData(grpc::ServerContext* context,
                                       const SetTreeMetaDataRequest* request,
                                       SetTreeMetaDataResponse* response) final {
    meta_data[request->data().num()].num = request->data().num();
    meta_data[request->data().num()].name = request->data().name();
    return grpc::Status();
  }
};

std::unique_ptr<Database> CreateDatabase()
{
  return std::make_unique<InMemoryDatabase>();
}
