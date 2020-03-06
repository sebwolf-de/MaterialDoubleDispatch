#include <chrono>
#include <ctime>
#include <vector>

#include "Material.h"
#include "FluxFactory.h"


int main(int argc, const char** argv) {
  std::vector<Material*> materials;
  materials.emplace_back(new AcousticMaterial());
//  materials.emplace_back(new PoroelasticMaterial());
  auto em = new ElasticMaterial();
  em->lambda = 1.0;
  materials.emplace_back(em);
  materials.emplace_back(new PoroelasticMaterial());
  materials.emplace_back(new AcousticMaterial());
  materials.emplace_back(new ElasticMaterial());

  for(auto m : materials) {
    for(auto n: materials) {
      std::string text = "additonal data ";
      auto now = std::chrono::system_clock::now();
      text.append(std::to_string(std::chrono::system_clock::to_time_t(now))) ;

      computeFlux(m, n, {text});
    }
  }

  return 0;
}
























































































































