#include "database.h"

#include <sw/redis++/redis++.h>
class Redis final : public Database {
 private:
  std::unique_ptr<sw::redis::Redis> redis_client_;

 public:
  Redis() {
    /*
        "keyspace": "m1",
      "host": "localhost",
      "port": 6379,
      "pool_size": 16,
      "subscriber_pool_size": 8
    */
    /* create the redis object here? */
    /* maybe create the redis object in the getinstance fuinction*/
    sw::redis::ConnectionOptions conn_opts;
    conn_opts.host = "localhost";
    conn_opts.port = 6379;
    conn_opts.socket_timeout = std::chrono::milliseconds(0);

    sw::redis::ConnectionPoolOptions conn_pool;
    conn_pool.size = 16;

    try {
      redis_client_ = std::make_unique<sw::redis::Redis>(conn_opts, conn_pool);

      if (redis_client_ == nullptr) {
        std::cout << "Failed to allocate client for redis " << conn_opts.host << ":"
                  << conn_opts.port;
        // This maynot be the best thing to do here. We should probably throw a
        // more specialized exception
        throw(std::runtime_error("Failed to allocate client for redis!"));
      }
    } catch (const std::exception& err) {
      std::cout << "Redis connection failed: {}" << err.what();
      throw(err);
    }
  }
  virtual ~Redis() {}
  virtual grpc::Status GetTreeMetaData(grpc::ServerContext* context,
                                       const GetTreeMetaDataRequest* request,
                                       GetTreeMetaDataResponse* response) final {
    std::unordered_map<std::string, std::string> data;
    try {
      redis_client_->hgetall("asdf:" + std::to_string(request->tree_num()),
                             std::inserter(data, data.begin()));
    } catch (const std::exception& err) {
      std::cout << "Unable to get hash @ " <<  err.what();
      throw err;
    }
    response->mutable_data()->set_num(std::stoull(data["num"]));
    response->mutable_data()->set_name(data["name"]);
    return grpc::Status();
  }

  virtual grpc::Status SetTreeMetaData(grpc::ServerContext* context,
                                       const SetTreeMetaDataRequest* request,
                                       SetTreeMetaDataResponse* response) final {
    std::unordered_map<std::string, std::string> value{{"num", std::to_string(request->data().num())}, {"name", request->data().name()}};
    try {
      redis_client_->hset("asdf:" + std::to_string(request->data().num()), value.begin(),
                          value.end());
    } catch (const std::exception& err) {
      std::cout << "Unable to store Hash in redis: " << err.what();
      throw err;
    }
    return grpc::Status();
  }
};

std::unique_ptr<Database> CreateDatabase()
{
  return std::make_unique<Redis>();
}
