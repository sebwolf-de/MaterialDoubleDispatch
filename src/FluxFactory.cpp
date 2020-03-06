#include "FluxFactory.h"
#include "Material.h"

#define GENERATE_FLUXFACTORY(NAME) \
  NAME ## FluxFactory:: NAME ## FluxFactory(const NAME ## Material* m) : FluxFactory(m), m(m) {} \
  void NAME ## FluxFactory::printInfo() { \
    std::cout << # NAME << "FluxFactory" << std::endl; \
  } \
  void NAME ## FluxFactory::flux(Material* m, AdditionalData payload) { \
    m->getFluxFactory()->fluxWith(this, payload); \
  } \
  void FluxFactory::fluxWith(NAME ## FluxFactory* f, AdditionalData payload) { \
    std::cout << "Not implemented!" << std::endl; \
  } \
  
void computeFlux(Material* loc, Material* neigh, AdditionalData payload) {
  std::cout << materialToString(loc->getType()) << "/" << materialToString(neigh->getType()) << ": ";
//  loc->flux(neigh);

  loc->getFluxFactory()->flux(neigh, payload);
}


/*
 * Flux Factory
 */
FluxFactory::FluxFactory(const Material* m) : m(m) {}

void FluxFactory::printInfo() {
  std::cout << "FluxFactory" << std::endl;
}

void FluxFactory::fluxWith(FluxFactory* f, AdditionalData payload) {
  std::cout << "not implemented" << std::endl;
}

/*
 * Elastic Flux Factory
 */
GENERATE_FLUXFACTORY(Elastic)

void ElasticFluxFactory::fluxWith(ElasticFluxFactory* f, AdditionalData payload) {
  std::cout << this->m->lambda << "/" << f->m->lambda;
  std::cout << "Elastic - Elastic coupling: " << this->m->lambda << "/" << f->m->lambda << " "<< payload.text << std::endl;
}


/*
 * Acoustic Flux Factory
 */
GENERATE_FLUXFACTORY(Acoustic)

void AcousticFluxFactory::fluxWith(AcousticFluxFactory* f, AdditionalData payload) {
  std::cout << "Acoustic - Acoustic coupling: " << payload.text << std::endl;
}

/*
 * Poroelastic Flux Factory
 */
GENERATE_FLUXFACTORY(Poroelastic)
