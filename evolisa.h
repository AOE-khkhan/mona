#pragma once

#define kEvoAlphaLimit 0.2            // alpha limit for images
#define kEvoAlphaOffset (kEvoAlphaLimit/2) //alpha offset
#define kEvoCheckLimit 150 //number of times we have a non-improving value before we terminate
#define kEvoOutputScale 2 //the factor by which we would like to scale up the image in the final render
#define kEvoImageWidth ((float) 300) //width of lisa.jpg
#define kEvoImageHeight ((float) 391) //height of lisa.jpg
#define kEvoPsoParticleCount 30    // number of particles for PSO
#define kEvoBlockDim 16   // grid width/height
#define kEvoPsoIterationCount 1000 // maximum number of iterations at each PSO stage (overridden by checklimit)
#define kEvoMaxTriangleCount 800 // number of triangles to render (max)
#define kEvoPsoNeighborhoodSize 12 // Size of neighbhorhood (PSO topology)

//rgb class! initialized with float4's from our texture memory
class rgba {
public:
	float r;
	float g;
	float b;
	float a;
#ifdef __CUDACC__
	__device__ rgba() {
	}
	inline __device__ rgba(float4 f) {
		r = f.x;
		g = f.y;
		b = f.z;
		a = f.w;
	}
#endif
};

//triangle class. stores color/alpha values, as well as coordinates of vertices
class triangle {
public:
	float x1;
	float y1;
	float x2;
	float y2;
	float x3;
	float y3;
	rgba c;
};