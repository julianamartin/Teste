#include "pch.h"
#include "Jogo.h"

//static const float VIEW_HEIGHT = 512.0f;

//void ResizeView(const RenderWindow& window, View& view);

int main()
{
	Jogo jogo;
	jogo.Executar();
	//RenderWindow window(VideoMode(1920, 1080), "Inimigos da DP", Style::Close | Style::Resize);
	//View view(sf::Vector2f(0.0f, 0.0f), Vector2f(VIEW_HEIGHT, VIEW_HEIGHT));
	
	//Plataforma plat1(&plat1Texture, Vector2f(1000.0f, 900.0f), Vector2f(500.0f, 700.0f));
	
		

		//window.setView(view);

	

	return 0;
}

/*void ResizeView(const sf::RenderWindow& window, sf::View& view)
{
	float proporção = (float) window.getSize().x / (float)window.getSize().y;
	view.setSize(VIEW_HEIGHT * proporção, VIEW_HEIGHT);
}*/

#include "Plataforma.h"

/*int main()
{
	RenderWindow win(VideoMode(1920, 1080), "SFML Tutorial", Style::Resize | Style::Close);
	Plataforma ObjPlat;
	//RectangleShape rectang(Vector2f(500.0f, 500.0f));

	while (win.isOpen())
	{
		Event evnt;
		while (win.pollEvent(evnt))
		{

			switch (evnt.type)
			{
			case Event::Closed:
				win.close();
				break;
			}
		}

		win.clear(Color(150, 150, 150));
		ObjPlat.Inicializa1();
		ObjPlat.Desenha(win);
		win.display();
	}

	return 0;
}*/
