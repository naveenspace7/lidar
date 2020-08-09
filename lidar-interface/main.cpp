#include <iostream>
#include "cmd.hpp"

using namespace std;

RESET * reset_cmd = reset_cmd->getInst();
STOP * stop_cmd = stop_cmd->getInst();
GET_INFO * get_info_cmd = get_info_cmd->getInst();
GET_HEALTH * get_health_cmd = get_health_cmd->getInst();
GET_SAMPLERATE * get_samplerate_cmd = get_samplerate_cmd->getInst();
SCAN * scan_cmd = scan_cmd->getInst();

int main()
{
    reset_cmd->execute();
    stop_cmd->execute();

    get_info_cmd->execute();
    get_health_cmd->execute();
    get_samplerate_cmd->execute();

    scan_cmd->execute();
}