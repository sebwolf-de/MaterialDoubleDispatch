#include "FluxFactory.h"
#include "Material.h"

#define GENERATE_FLUXFACTORY(NAME) \
  NAME ## FluxFactory:: NAME ## FluxFactory(const NAME ## Material* m) : FluxFactory(m), m(m) {} \
  void NAME ## FluxFactory::printInfo() { \
    std::cout << # NAME << "FluxFactory" << std::endl; \
  } \
  std::string NAME ## FluxFactory::flux(Material* m, AdditionalData payload) { \
    return m->getFluxFactory()->fluxWith(this, payload); \
  } \
  std::string FluxFactory::fluxWith(NAME ## FluxFactory* f, AdditionalData payload) { \
    return "Not implemented!"; \
  } \
  
std::string computeFlux(Material* loc, Material* neigh, AdditionalData payload) {
  return loc->getFluxFactory()->flux(neigh, payload);
}


/*
 * Flux Factory
 */
FluxFactory::FluxFactory(const Material* m) : m(m) {}

void FluxFactory::printInfo() {
  std::cout << "FluxFactory" << std::endl;
}

std::string FluxFactory::fluxWith(FluxFactory* f, AdditionalData payload) {
  return "not implemented";
}

/*
 * Elastic Flux Factory
 */
GENERATE_FLUXFACTORY(Elastic)

std::string ElasticFluxFactory::fluxWith(ElasticFluxFactory* f, AdditionalData payload) {
  std::string ret = "Elastic - Elastic coupling ";
  ret = ret.append(std::to_string(f->m->lambda));
  ret = ret.append("/");
  ret = ret.append(std::to_string(this->m->lambda));
  return ret;
}

std::string ElasticFluxFactory::fluxWith(AcousticFluxFactory* f, AdditionalData payload) {
  return "Acoustic - Elastic coupling";
}


/*
 * Acoustic Flux Factory
 */
GENERATE_FLUXFACTORY(Acoustic)

std::string AcousticFluxFactory::fluxWith(AcousticFluxFactory* f, AdditionalData payload) {
  return std::string("Acoustic - Acoustic coupling: ").append(payload.text);
}

/*
 * Poroelastic Flux Factory
 */
GENERATE_FLUXFACTORY(Poroelastic)
