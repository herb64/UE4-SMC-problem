// Some test code for investigating the "vanishing static mesh" property within
// C++ Static Mesh Components when recompiling.
// Herbert Mehlhose (herb64) - 15.05.2019


// BTW: I had to add ../Public/ path prefix manually here, because even
// with the default code created by UE4, intellisense otherwise complains
// about "cannot find include file" (Compile works in any case)
#include "../Public/SMC_test.h"
#include "Engine/StaticMesh.h"
#include "Runtime/CoreUObject/Public/UObject/ConstructorHelpers.h"


// Just switch workaround off by commenting this
//#define WORKAROUND

/*
 * W O R K A R O U N D   F O R   V A N I S H I N G   S T A T I C  M E S H
 * Set static mesh within the constructor manually
 */
USMC_test::USMC_test()
{
#ifdef WORKAROUND
	// We simply use the Engine Cone Basic Shape
	static ConstructorHelpers::FObjectFinder<UStaticMesh>SM_Cone(TEXT("/Engine/BasicShapes/Cone.Cone"));
	UStaticMesh* EngineConeMesh = SM_Cone.Object;
	if (EngineConeMesh != nullptr) {
		this->SetStaticMesh(EngineConeMesh);
	} else {
		UE_LOG(LogTemp, Error, TEXT("Could not set static mesh to component"));
	}
#endif
}