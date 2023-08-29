#pragma once

#include "protos/testserver.grpc.pb.h"
#include <grpcpp/ext/proto_server_reflection_plugin.h>
#include <grpcpp/grpcpp.h>
#include <grpcpp/health_check_service_interface.h>
#include "paho-mqtt-cpp/include/mqtt/client.h"
#include "announcer.h"

class MqttAnnouncer final : public Announcer {
 private:
  mqtt::client client;
  mqtt::connect_options connOpts;
 public:
  MqttAnnouncer(void):client("tcp://localhost:1883", "voodoo")
  {
    connOpts.set_keep_alive_interval(20);
    connOpts.set_clean_session(true);
    client.connect(connOpts);
  }
  virtual ~MqttAnnouncer() {}
  virtual grpc::Status SetTreeMetaData(grpc::ServerContext* context,
                                       const SetTreeMetaDataRequest* request,
                                       SetTreeMetaDataResponse* response) final
  {
    GetTreeMetaDataResponse to_broadcast;
    to_broadcast.mutable_data()->set_num(request->data().num());
    to_broadcast.mutable_data()->set_name(request->data().name());
    auto pubmsg = mqtt::make_message("/hello/world/", to_broadcast.SerializeAsString());
    pubmsg->set_qos(1);
    client.publish(pubmsg);
    return grpc::Status();
  }
};

extern std::unique_ptr<Announcer> CreateAnnouncer()
{
  return std::make_unique<MqttAnnouncer>();
}
