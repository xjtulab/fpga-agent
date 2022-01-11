#include "FpgaController.hpp"


void FpgaController::registerFpgaService(){
    /* request executor should be previously initialized */

    /* get oatpp::consul::rest::Client */
    auto restClient = m_consulClient->getRestClient();

    auto checkPayload = oatpp::consul::rest::AgentCheckRegisterPayload::createShared();
    checkPayload->serviceID = "service_check_id";
    checkPayload->name = "service_check_name";
    checkPayload->notes = "Check on the MyService/Health endpoint";
    checkPayload->http = "http://localhost:8000/check/health";
    checkPayload->method = "GET";
    checkPayload->interval = "30s";
    checkPayload->timeout = "15s";

    auto payload = oatpp::consul::rest::AgentServiceRegisterPayload::createShared();
    payload->id = "service_id";
    payload->name = "service_name";
    payload->port = 8000;
    payload->check = checkPayload;

    /* make API call */
    auto response = restClient->agentServiceRegister(payload);
    OATPP_LOGD("consul", "response='%s'", response->readBodyToString()->c_str());

    // Regist start process service
    payload = oatpp::consul::rest::AgentServiceRegisterPayload::createShared();
    payload->id = "f1";
    payload->name = "fpga_start_process";
    payload->port = 8000;
    response = restClient->agentServiceRegister(payload);

    OATPP_LOGD("consul", "regist fpga_start_service response='%s'", response->readBodyToString()->c_str());

    // Regist stop process service
    payload = oatpp::consul::rest::AgentServiceRegisterPayload::createShared();
    payload->id = "f2";
    payload->name = "fpga_stop_process";
    payload->port = 8000;
    response = restClient->agentServiceRegister(payload);

    OATPP_LOGD("consul", "regist fpga_stop_service response='%s'", response->readBodyToString()->c_str());

    // Regist stat process service
    payload = oatpp::consul::rest::AgentServiceRegisterPayload::createShared();
    payload->id = "f3";
    payload->name = "fpga_stat_process";
    payload->port = 8000;
    response = restClient->agentServiceRegister(payload);

    OATPP_LOGD("consul", "regist fpga_stat_service response='%s'", response->readBodyToString()->c_str());

}

oatpp::String FpgaController::startFpgaProcess(String name){
    //todo: send start msg to device and change response


    std::string str = "Start process ";
    str += name->c_str();
    return String(str);
}

oatpp::String FpgaController::stopFpgaProcess(String name){
    //todo: send stop msg to  and change response

    std::string str = "Stop process ";
    str += name->c_str();
    return String(str);
}

oatpp::String FpgaController::startPerf(){
    //todo: send perf msg to  and change response

    std::string str = "Start performance monitor ";
    return String(str);
}