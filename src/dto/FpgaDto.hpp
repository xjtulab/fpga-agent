#ifndef FpgaDto_hpp
#define FpgaDto_hpp

#include "oatpp/core/data/mapping/type/Object.hpp"
#include "oatpp/core/macro/codegen.hpp"

#include OATPP_CODEGEN_BEGIN(DTO)

/**
 *  Data Transfer Object. Object containing fields only.
 *  Used in API for serialization/deserialization and validation
 */
class FpgaDto : public oatpp::DTO {
  
  DTO_INIT(FpgaDto, DTO)
  
  DTO_FIELD(String, status);
  
};

#include OATPP_CODEGEN_END(DTO)

#endif /* FpgaDto_hpp */
