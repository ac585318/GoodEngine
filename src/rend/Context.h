#include <sr1/memory>
#include <SDL2/SDL.h>

namespace rend
{

struct Texture;
struct Shader;
struct Buffer;
struct RenderTexture;
struct Mesh;

struct Context
{
	~Context();

  static std::sr1::shared_ptr<Context> initialize(SDL_Window* _window);

  std::sr1::shared_ptr<Texture> createTexture();
  std::sr1::shared_ptr<Shader> createShader();
  std::sr1::shared_ptr<Buffer> createBuffer();
  std::sr1::shared_ptr<Mesh> createMesh();
  std::sr1::shared_ptr<RenderTexture> createRenderTexture();

private:
  std::sr1::weak_ptr<Context> self;
  SDL_Window* window;

};

}
