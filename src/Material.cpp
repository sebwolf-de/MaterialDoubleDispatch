#include "Material.h"
#include "FluxFactory.h"

void Material::print() const { 
  std::cout << "Material" << std::endl
    << "rho = " << rho << std::endl; 
}

MaterialType Material::getType() const { 
  return MaterialType::none; 
}

//FluxFactory* Material::getFluxFactory() const {
//  return new FluxFactory(this);
//}

void ElasticMaterial::print() const { 
  std::cout << "Elastic Material" << std::endl 
    << "rho =    " << rho << std::endl
    << "mu =     " << mu << std::endl
    << "lambda = " << lambda << std::endl; 
};

MaterialType ElasticMaterial::getType() const { 
  return MaterialType::elastic; 
}

FluxFactory* ElasticMaterial::getFluxFactory() const {
  return new ElasticFluxFactory(this);
}

void AcousticMaterial::print() const { 
  std::cout << "Acoustic Material" << std::endl 
    << "rho =    " << rho << std::endl
    << "mu =     " << mu << std::endl;
};

MaterialType AcousticMaterial::getType() const { 
  return MaterialType::acoustic; 
}

FluxFactory* AcousticMaterial::getFluxFactory() const {
  return new AcousticFluxFactory(this);
}

void PoroelasticMaterial::print() const { 
  std::cout << "Poroelastic Material" << std::endl 
    << "rho =   " << rho << std::endl
    << "nu =    " << nu << std::endl
    << "kappa = " << kappa << std::endl; 
};


MaterialType PoroelasticMaterial::getType() const { 
  return MaterialType::poroelastic; 
}

FluxFactory* PoroelasticMaterial::getFluxFactory() const {
  return new PoroelasticFluxFactory(this);
}
