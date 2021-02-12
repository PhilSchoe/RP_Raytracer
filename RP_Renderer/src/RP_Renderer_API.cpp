// RP_Renderer.cpp : Defines the exported functions for the DLL.


#include "RP_Renderer_API.h"
#include "Renderer.h"


RPRENDERER_API void renderImage( int width, int height, float* outputImage )
{
    Renderer renderer;
    renderer.renderImage( width, height, outputImage );
}