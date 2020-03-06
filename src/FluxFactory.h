#ifndef FLUXFACTORY_H_
#define FLUXFACTORY_H_

#include <iostream>

class Material;
class ElasticMaterial;
class AcousticMaterial;
class PoroelasticMaterial;

class FluxFactory;
class ElasticFluxFactory;
class AcousticFluxFactory;
class PoroelasticFluxFactory;

struct AdditionalData;

std::string computeFlux(Material* loc, Material* neigh, AdditionalData payload);

class FluxFactory {
  public:
  FluxFactory(const Material* m);

  virtual void printInfo() = 0;
  virtual std::string flux(Material* m, AdditionalData payload) = 0;

  virtual std::string fluxWith(FluxFactory* f, AdditionalData payload);
  virtual std::string fluxWith(ElasticFluxFactory* f, AdditionalData payload);
  virtual std::string fluxWith(AcousticFluxFactory* f, AdditionalData payload);
  virtual std::string fluxWith(PoroelasticFluxFactory* f, AdditionalData payload);

  private:
  const Material* m;
};

class ElasticFluxFactory : public FluxFactory {
  public:
  ElasticFluxFactory(const ElasticMaterial* m);

  virtual void printInfo() override;
  virtual std::string flux(Material* m, AdditionalData payload) override;

  virtual std::string fluxWith(ElasticFluxFactory* f, AdditionalData payload) override;
  virtual std::string fluxWith(AcousticFluxFactory* f, AdditionalData payload) override;

  private:
  const ElasticMaterial* m;
};

class AcousticFluxFactory : public FluxFactory {
  public:
  AcousticFluxFactory(const AcousticMaterial* m);

  virtual void printInfo() override;
  virtual std::string flux(Material* m, AdditionalData payload) override;

  virtual std::string fluxWith(AcousticFluxFactory* f, AdditionalData payload) override;

  private:
  const AcousticMaterial* m;
};

class PoroelasticFluxFactory: public FluxFactory {
  public:
  PoroelasticFluxFactory(const PoroelasticMaterial* m);

  virtual void printInfo() override;
  virtual std::string flux(Material* m, AdditionalData payload) override;

  private:
  const PoroelasticMaterial* m;
};
#endif
