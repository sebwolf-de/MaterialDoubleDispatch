#ifndef MATERIAL_H_
#define MATERIAL_H_

#include <iostream>
#include <string>

#include "FluxFactory.h"

enum class MaterialType {
  none,
  elastic,
  acoustic,
  poroelastic
};

inline std::string materialToString(MaterialType mt) {
  switch(mt) {
    case MaterialType::none:        return "None";
    case MaterialType::elastic:     return "Elastic";
    case MaterialType::acoustic:    return "Acoustic";
    case MaterialType::poroelastic: return "Poroelastic";
  }

}

class Material;
class ElasticMaterial;
class AcousticMaterial;
class PoroelasticMaterial;

class Material {
  public:
  double rho;

  virtual void print() const;
  virtual MaterialType getType() const;

  virtual FluxFactory* getFluxFactory() const = 0;
};

class ElasticMaterial : public Material {
  public:
  double lambda, mu;

  virtual void print() const override;
  virtual MaterialType getType() const override;

  virtual FluxFactory* getFluxFactory() const override;
};

class AcousticMaterial : public Material {
  public:
  double mu;

  virtual void print() const override;
  virtual MaterialType getType() const override;

  virtual FluxFactory* getFluxFactory() const override;
};

class PoroelasticMaterial : public Material {
  public:
  double kappa, nu;

  virtual void print() const override;
  virtual MaterialType getType() const override;

  virtual FluxFactory* getFluxFactory() const override;
};

struct AdditionalData {
  std::string text;
};

#endif
