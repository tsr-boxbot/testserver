#include "paho-mqtt-cpp/include/mqtt/client.h"

int main(void)
{
    mqtt::client client("tcp://localhost:1883", "sync_publish_cpp");
    mqtt::connect_options connOpts;
    connOpts.set_keep_alive_interval(20);
    connOpts.set_clean_session(true);
    client.connect(connOpts);
    auto pubmsg = mqtt::make_message("/hello/world/", "hi");
    pubmsg->set_qos(1);
    client.publish(pubmsg);
    return 0;
}
