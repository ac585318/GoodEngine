#include "Texture.h"

#define STB_IMAGE_IMPLEMENTATION	// Only need to define this once
#include "stb_image.h"

#include <rend/rend.h>
#include <SDL2/SDL.h>
#include <iostream>
#include <fstream>

#include "Core.h"

namespace goodengine {

	Texture::~Texture()
	{

	}

	void Texture::load(std::string _path)
	{
		path = _path;

		texture = core.lock()->getContext()->createTexture();

		if (texture)
		{
			int w = 0;
			int h = 0;
			int bpp = 0;

			//_path.c_str()
			unsigned char *data = stbi_load(_path.c_str(),
				&w, &h, &bpp, 3);

			if (!data)
			{
				throw std::exception("Failed to open image");
			}

			texture->setSize(w, h);

			for (int y = 0; y < h; y++)
			{
				for (int x = 0; x < w; x++)
				{
					int r = y * w * 3 + x * 3;

					texture->setPixel(x, y, glm::vec3(
						data[r] / 255.0f,
						data[r + 1] / 255.0f,
						data[r + 2] / 255.0f));
				}
			}

			stbi_image_free(data);
		}

	}

}