#include <cxxtest/TestSuite.h>

#include "../FluxFactory.h"
#include "../Material.h"

class computeFluxSuite : public CxxTest::TestSuite
{
public:
   void test_elastic_elastic( void )
   {
     auto* mat1 = new ElasticMaterial();
     mat1->lambda = 1.0;
     auto* mat2 = new ElasticMaterial();
     mat2->lambda = 2.0;

     auto computedString = computeFlux(mat1, mat2, {""});
     auto expectedString = "Elastic - Elastic coupling 1.000000/2.000000";
     TS_ASSERT(computedString == expectedString);
   }

   void test_acoustic_elastic( void )
   {
     auto* mat1 = new AcousticMaterial();
     auto* mat2 = new ElasticMaterial();

     auto computedString = computeFlux(mat1, mat2, {""});
     auto expectedString = "Acoustic - Elastic coupling";
     TS_ASSERT(computedString == expectedString);
   }

   void test_acoustic_acoustic( void )
   {
     auto* mat1 = new AcousticMaterial();
     auto* mat2 = new AcousticMaterial();

     auto computedString = computeFlux(mat1, mat2, {"test123"});
     auto expectedString = "Acoustic - Acoustic coupling: test123";
     TS_ASSERT(computedString == expectedString);
   }

   void test_elastic_acoustic( void )
   {
     auto* mat1 = new ElasticMaterial();
     auto* mat2 = new AcousticMaterial();

     auto computedString = computeFlux(mat1, mat2, {""});
     auto expectedString = "Not implemented!";
     TS_ASSERT(computedString == expectedString);
   }

   void test_elastic_poroelastic( void )
   {
     auto* mat1 = new ElasticMaterial();
     auto* mat2 = new PoroelasticMaterial();

     auto computedString = computeFlux(mat1, mat2, {""});
     auto expectedString = "Not implemented!";
     TS_ASSERT(computedString == expectedString);
   }

   void test_acoustic_poroelastic( void )
   {
     auto* mat1 = new AcousticMaterial();
     auto* mat2 = new PoroelasticMaterial();

     auto computedString = computeFlux(mat1, mat2, {""});
     auto expectedString = "Not implemented!";
     TS_ASSERT(computedString == expectedString);
   }

   void test_poroelastic_acoustic( void )
   {
     auto* mat1 = new PoroelasticMaterial();
     auto* mat2 = new AcousticMaterial();

     auto computedString = computeFlux(mat1, mat2, {""});
     auto expectedString = "Not implemented!";
     TS_ASSERT(computedString == expectedString);
   }
   void test_poroelastic_elastic( void )
   {
     auto* mat1 = new PoroelasticMaterial();
     auto* mat2 = new ElasticMaterial();

     auto computedString = computeFlux(mat1, mat2, {""});
     auto expectedString = "Not implemented!";
     TS_ASSERT(computedString == expectedString);
   }

   void test_poroelastic_poroelastic( void )
   {
     auto* mat1 = new PoroelasticMaterial();
     auto* mat2 = new PoroelasticMaterial();

     auto computedString = computeFlux(mat1, mat2, {""});
     auto expectedString = "Not implemented!";
     TS_ASSERT(computedString == expectedString);
   }
};
