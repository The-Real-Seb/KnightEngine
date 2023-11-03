#include "CSpriteRenderer.h"
#include "Application.h"

KE::CSpriteRenderer::CSpriteRenderer():AComponent()
{
}

KE::CSpriteRenderer::~CSpriteRenderer()
{
	delete &_sprite;
	delete & _texture;
}

void KE::CSpriteRenderer::SetSprite()
{
	_sprite.setTexture(_texture);
}

void KE::CSpriteRenderer::SetSprite(bool isSmooth, std::string path, sf::Color color)
{
	SetTexture(path);
	_texture.setSmooth(true);

	_sprite.setOrigin(sf::Vector2f(_texture.getSize().x / 2, _texture.getSize().y / 2));
	_sprite.setPosition(KE::Application::GetInstance()->GetParent(this)->getPosition());
	_sprite.setScale(sf::Vector2f(0.1f, 0.1f));
	_sprite.setTexture(_texture);
	SetColor(color);	
}

void KE::CSpriteRenderer::SetTexture(std::string path)
{
	if (!_texture.loadFromFile(path))
	{
		std::cout << "Impossible de load la texture, chemin non trouvé..." << std::endl;
	}
}

void KE::CSpriteRenderer::SetColor(sf::Color color)
{
	_sprite.setColor(color);
}

void KE::CSpriteRenderer::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
	target.draw(_sprite, states);
}
