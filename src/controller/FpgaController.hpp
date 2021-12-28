#ifndef FpgaController_hpp
#define FpgaController_hpp

#include "oatpp-consul/rest/DTOs.hpp"
#include "oatpp-consul/Client.hpp"
#include "dto/FpgaDto.hpp"

#include "oatpp/web/server/api/ApiController.hpp"
#include "oatpp/parser/json/mapping/ObjectMapper.hpp"
#include "oatpp/core/macro/codegen.hpp"
#include "oatpp/core/macro/component.hpp"

#include OATPP_CODEGEN_BEGIN(ApiController) //<-- Begin codegen

/**
 *  EXAMPLE ApiController
 *  Basic examples of howto create ENDPOINTs
 *  More details on oatpp.io
 */
class FpgaController : public oatpp::web::server::api::ApiController {
protected:
  FpgaController(const std::shared_ptr<ObjectMapper>& objectMapper)
    : oatpp::web::server::api::ApiController(objectMapper)
  {}
public:

  /*
   * Register service.
   */
  void registerFpgaService();

  
  /**
   *  Inject @objectMapper component here as default parameter
   *  Do not return bare Controllable* object! use shared_ptr!
   */
  static std::shared_ptr<FpgaController> createShared(OATPP_COMPONENT(std::shared_ptr<ObjectMapper>,
                                                                        objectMapper)){
    return std::shared_ptr<FpgaController>(new FpgaController(objectMapper));
  }

  /**
   *  This is my code.
   */

  ENDPOINT("GET", "fpga/echo", fpgaEcho) {
    
    auto status = FpgaDto::createShared();
    status->status = "This is fpga device";
    
    OATPP_LOGD("fpga", "echo");
    
    return createDtoResponse(Status::CODE_200, status);
  }

  // Start process
  ENDPOINT("GET", "fpga/start/{process_name}", fpgaStart,
        PATH(String, process_name)) {

    //String type is a shared_ptr<std::string>
    auto status = FpgaDto::createShared();
    status->status = startFpgaProcess(process_name);
    
    OATPP_LOGD("fpga", "start process '%s'", process_name->c_str());
    
    return createDtoResponse(Status::CODE_200, status);
  }

  // Stop process
  ENDPOINT("GET", "fpga/stop/{process_name}", fpgaStop,
        PATH(String, process_name)) {

    //String type is a shared_ptr<std::string>
    auto status = FpgaDto::createShared();
    status->status = stopFpgaProcess(process_name);

    OATPP_LOGD("fpga", "stop process '%s'", process_name->c_str());
    
    return createDtoResponse(Status::CODE_200, status);
  }

  // Start performance monitor
  ENDPOINT("GET", "fpga/perf", fpgaPerf) {

    //String type is a shared_ptr<std::string>
    auto status = FpgaDto::createShared();
    status->status = startPerf();

    OATPP_LOGD("fpga", "start performance monitor");
    
    return createDtoResponse(Status::CODE_200, status);
  }


private:

    OATPP_COMPONENT(std::shared_ptr<oatpp::consul::Client>, m_consulClient);

    oatpp::String startFpgaProcess(String name);
    oatpp::String stopFpgaProcess(String name);
    oatpp::String startPerf();
  
};

#include OATPP_CODEGEN_END(ApiController) //<-- End codegen

#endif