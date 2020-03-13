#include <cxxtest/TestSuite.h>

#include "../FluxFactory.h"
#include "../Material.h"

class materialSuite : public CxxTest::TestSuite
{
public:
   void test_type( void )
   {
     auto* mat1 = new ElasticMaterial();
     TS_ASSERT(mat1->getType() == MaterialType::elastic);
     auto* mat2 = new AcousticMaterial();
     TS_ASSERT(mat2->getType() == MaterialType::acoustic);
     auto* mat3 = new PoroelasticMaterial();
     TS_ASSERT(mat3->getType() == MaterialType::poroelastic);
   }
};
