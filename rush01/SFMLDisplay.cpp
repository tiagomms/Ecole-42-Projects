// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   SFMLDisplay.cpp                                  :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: lperrigu <marvin@42.fr>                    +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2015/06/27 19:30:50 by lperrigu          #+#    #+#             //
//   Updated: 2015/06/28 18:36:09 by lperrigu         ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#include "SFMLDisplay.hpp"


SFMLDisplay::SFMLDisplay( void )
{
    if (!this->_mainTexture.loadFromFile("textures/ios-background.jpg"))
	{
    	std::cerr << "error with textute. Try again" << std::endl;
    	exit(1);
	}

	if (!this->_spriteTexture.loadFromFile("textures/insideTexture.jpg"))
	{
    	std::cerr << "error with textute. Try again" << std::endl;
    	exit(1);
	}

	if (!this->_font.loadFromFile("fonts/Caliban.ttf"))
	{
    	std::cerr << "error with font. Try again" << std::endl;
    	exit(1);
	}
}

SFMLDisplay::SFMLDisplay( int width, int height, int startx, int starty,
				   IMonitorModule *mod ) :
	_width( width ), _height( height ), _startx( startx ), _starty( starty ),
	_mod( mod )
{

//	this->refresh();
}

/*
SFMLDisplay::SFMLDisplay( SFMLDisplay &instance )
{

}

SFMLDisplay& SFMLDisplay::operator=( SFMLDisplay const &rhs )
{

}
*/

SFMLDisplay::~SFMLDisplay( void )
{
	
}

/*

void	SFMLDisplay::run( void )
{
	sf::RenderWindow this->_mainWindow(sf::VideoMode(1200, 880), "ft_gkrellm", 
		sf::Style::Default);
	sf::Vector2u window_size = this->_mainWindow.getSize();
	this->_mainWindow.setVerticalSyncEnabled(true);


	std::list<IMonitorDisplay *> modules;

	modules.push_back(new SFMLDisplay( (window_size.x / 2) - 40, (window_size.y / 3) - 40, 
										20, 20, new RAM ) );

	modules.push_back(new SFMLDisplay( (window_size.x / 2) - 40, (window_size.y / 3) - 40,
										 (window_size.x / 2) + 20, 20, new OSInfo ) );

	modules.push_back(new SFMLDisplay( (window_size.x / 2) - 40, (window_size.y / 3) - 40,
										 20, (window_size.y / 3) + 20, new Network ) );

	modules.push_back(new SFMLDisplay( (window_size.x / 2) - 40, (window_size.y / 3) - 40,
										 (window_size.x / 2) + 20, (window_size.y / 3) + 20, new DateTime ) );

	modules.push_back(new SFMLDisplay( (window_size.x / 2) - 40, (window_size.y / 3) - 40,
										 20, ((window_size.y / 3) + 20) * 2, new HostUserName ) );

	modules.push_back(new SFMLDisplay( (window_size.x / 2) - 40, (window_size.y / 3) - 40,
										 (window_size.x / 2) + 20, ((window_size.y / 3) + 20) * 2, new CPU ) );



    sf::Texture this->_mainTexture;
   	this->_mainTexture.update(this->_mainWindow); 

   	sf::Texture this->_spriteTexture;
    if (!this->_mainTexture.loadFromFile("textures/ios-background.jpg") && 
    	!this->_spriteTexture.loadFromFile("textures/insideTexture.jpg"))
	{
    	std::cerr << "error with textute. Try again" << std::endl;
    	exit(1);
	}

	sf::Font this->_font;
	if (!this->_font.loadFromFile("fonts/Caliban.ttf"))
	{
    	std::cerr << "error with font. Try again" << std::endl;
    	exit(1);
	}

	sf::Sprite this->_mainSprite;
	while (this->_mainWindow.isOpen())
	{

		window_size = this->_mainWindow.getSize();
		this->_mainSprite.setTexture(this->_mainTexture);
//		this->_mainSprite.setColor(sf::Color(255, 255, 255, 255));
		this->_mainSprite.setPosition(sf::Vector2f(0, 0)); // absolute position
		this->_mainSprite.setScale(
			sf::Vector2f(static_cast<float>(window_size.x)/this->_mainTexture.getSize().x, 
			static_cast<float>(window_size.y)/this->_mainTexture.getSize().y));
		this->_mainWindow.clear();
		this->_mainWindow.draw(this->_mainSprite);
		
		sf::Event event;
		while (this->_mainWindow.pollEvent(event))
		{
			switch (event.type)
			{
				case  sf::Event::Closed:
					this->_mainWindow.close();
					break;
				default:
					break;
			}
			//draw what i want		
		}
		for ( it = modules.begin(); it != ite; ++it)
			(*it)->refresh();
		this->_mainWindow.display();
	}	
}

*/

void	SFMLDisplay::run( void )
{
	this->_mainWindow.create(sf::VideoMode(1200, 880), "ft_gkrellm");
	sf::Vector2u window_size = this->_mainWindow.getSize();
	this->_mainWindow.setVerticalSyncEnabled(true);


	std::list<IMonitorDisplay *> modules;

	modules.push_back(new SFMLDisplay( (window_size.x / 2) - 40, (window_size.y / 3) - 40, 
										20, 20, new RAM ) );
/*
	modules.push_back(new SFMLDisplay( (window_size.x / 2) - 40, (window_size.y / 3) - 40,
										 (window_size.x / 2) + 20, 20, new OSInfo ) );

	modules.push_back(new SFMLDisplay( (window_size.x / 2) - 40, (window_size.y / 3) - 40,
										 20, (window_size.y / 3) + 20, new Network ) );

	modules.push_back(new SFMLDisplay( (window_size.x / 2) - 40, (window_size.y / 3) - 40,
										 (window_size.x / 2) + 20, (window_size.y / 3) + 20, new DateTime ) );

	modules.push_back(new SFMLDisplay( (window_size.x / 2) - 40, (window_size.y / 3) - 40,
										 20, ((window_size.y / 3) + 20) * 2, new HostUserName ) );

	modules.push_back(new SFMLDisplay( (window_size.x / 2) - 40, (window_size.y / 3) - 40,
										 (window_size.x / 2) + 20, ((window_size.y / 3) + 20) * 2, new CPU ) );
*/



	sf::Sprite _mainSprite;
	std::list<IMonitorDisplay*>::iterator it;
	std::list<IMonitorDisplay*>::iterator ite = modules.end();	
	while (this->_mainWindow.isOpen())
	{

		window_size = this->_mainWindow.getSize();
		_mainSprite.setTexture(this->_mainTexture);
		_mainSprite.setColor(sf::Color(255, 255, 255, 255));
		_mainSprite.setPosition(sf::Vector2f(0, 0)); // absolute position
		_mainSprite.setScale(
			sf::Vector2f(static_cast<float>(window_size.x)/this->_mainTexture.getSize().x, 
			static_cast<float>(window_size.y)/this->_mainTexture.getSize().y));
		this->_mainWindow.clear();
		this->_mainWindow.draw(_mainSprite);
		for ( it = modules.begin(); it != ite; ++it)
			(*it)->refresh();
		this->_mainWindow.display();		
		sf::Event event;
		while (this->_mainWindow.pollEvent(event))
		{
			switch (event.type)
			{
				case  sf::Event::Closed:
					this->_mainWindow.close();
					break;
				default:
					break;
			}
			//draw what i want		
		}
	}	
}

void    SFMLDisplay::refresh( void )
{


	RAM				*R = dynamic_cast<RAM *>(this->_mod);
	OSInfo			*O = dynamic_cast<OSInfo *>(this->_mod);
	Network			*N = dynamic_cast<Network *>(this->_mod);
	DateTime		*D = dynamic_cast<DateTime *>(this->_mod);
	HostUserName	*H = dynamic_cast<HostUserName *>(this->_mod);
	CPU				*C = dynamic_cast<CPU *>(this->_mod);	
	if (R != NULL)
		display(R);
	else if (O != NULL)
		display(O);
	else if (N != NULL)
		display(N);	
	else if (D != NULL)
		display(D);	
	else if (H != NULL)
		display(H);	
	else if (C != NULL)
		display(C);
/*	window.clear();
	window.draw(sprite);
	window.draw(text);
	window.display();*/
}

// ************************************************************************** //
// *****************************DISPLAY FUNCTIONS**************************** //
// ************************************************************************** //

void	SFMLDisplay::display( RAM *m )
{
	float	percentage_mem_free;
	float	percentage_mem_used;
	int		coord_y;
	int		coord_x;

   	m->execute();
	percentage_mem_free = static_cast<float>(m->getMemFree()) * 100 / m->getMemTotal();
	percentage_mem_used = static_cast<float>(m->getMemUsed()) * 100 / m->getMemTotal();

	sf::Sprite sprite;
   	sprite.setTexture(this->_spriteTexture);
	sprite.setColor(sf::Color(255, 255, 255, 160));
   	sprite.setPosition(sf::Vector2f(this->_startx, this->_starty));
	this->_mainWindow.draw(sprite);

    sf::Text text_title;
    text_title.setFont(this->_font);
    text_title.setString(m->getTitle());
    text_title.setCharacterSize(14);
    int centerWidth = (this->_width / 2) + this->_startx;
    coord_y = this->_starty + 7;
    text_title.setPosition(centerWidth, coord_y);
    text_title.setColor(sf::Color::Black);
    text_title.setStyle(sf::Text::Bold | sf::Text::Underlined);    
    this->_mainWindow.draw(text_title);
    
    coord_y += 20;
    coord_x = this->_startx + 10;
    
    sf::Text text_type1;
    text_type1.setFont(this->_font);
    text_type1.setString("Percentage of Free Memory:");
    text_type1.setCharacterSize(10);
    text_title.setPosition(coord_x, coord_y);    
    text_title.setColor(sf::Color::Blue);
    text_title.setStyle(sf::Text::Underlined);
    this->_mainWindow.draw(text_type1);

    sf::Text text_value1;
    text_value1.setFont(this->_font);
    std::string value = std::to_string(percentage_mem_free) + '%';
    text_value1.setString(value);
    text_title.setPosition(coord_x + 30, coord_y);
    text_value1.setCharacterSize(10);
    text_title.setColor(sf::Color::Green);
    this->_mainWindow.draw(text_value1);

    coord_y += 10;
    
    sf::Text text_type2;
    text_type2.setFont(this->_font);
    text_type2.setString("Percentage of Used Memory:");
    text_type2.setCharacterSize(10);
    text_title.setPosition(coord_x, coord_y);    
    text_title.setColor(sf::Color::Blue);
    text_title.setStyle(sf::Text::Underlined);
    this->_mainWindow.draw(text_type2);

    sf::Text text_value2;
    text_value2.setFont(this->_font);
    std::string value2 = std::to_string(percentage_mem_used) + '%';
    text_value2.setString(value2);
    text_title.setPosition(coord_x + 30, coord_y);
    text_value2.setCharacterSize(10);
    text_title.setColor(sf::Color::Red);
    this->_mainWindow.draw(text_value2);

    coord_y += 10;
    
    sf::Text text_type3;
    text_type3.setFont(this->_font);
    text_type3.setString("Total Memory (MB):");
    text_type3.setCharacterSize(10);
    text_title.setPosition(coord_x, coord_y);    
    text_title.setColor(sf::Color::Blue);
    text_title.setStyle(sf::Text::Underlined);
    this->_mainWindow.draw(text_type3);

    sf::Text text_value3;
    text_value3.setFont(this->_font);
    std::string value3 = std::to_string(m->getMemTotal() >> 20);
    text_value3.setString(value3);
    text_title.setPosition(coord_x + 30, coord_y);
    text_value3.setCharacterSize(10);
    text_title.setColor(sf::Color::Black);
    this->_mainWindow.draw(text_value3);
}	


void	SFMLDisplay::display( OSInfo *m )
{
	int		coord_y;
	int		coord_x;

   	m->execute();
	sf::Sprite sprite;
   	sprite.setTexture(this->_spriteTexture);
   	sprite.setPosition(sf::Vector2f(this->_startx, this->_starty));
	this->_mainWindow.draw(sprite);

    sf::Text text_title;
    text_title.setFont(this->_font);
    text_title.setString(m->getTitle());
    text_title.setCharacterSize(14);
    int centerWidth = (this->_width / 2) + this->_startx;
    coord_y = this->_starty + 7;
    text_title.setPosition(centerWidth, coord_y);
    text_title.setColor(sf::Color::Black);
    text_title.setStyle(sf::Text::Bold | sf::Text::Underlined);    
    this->_mainWindow.draw(text_title);
    
    coord_y += 20;
    coord_x = this->_startx + 10;
    
    sf::Text text_type1;
    text_type1.setFont(this->_font);
    text_type1.setString("Machine: ");
    text_type1.setCharacterSize(10);
    text_title.setPosition(coord_x, coord_y);    
    text_title.setColor(sf::Color::Blue);
    text_title.setStyle(sf::Text::Underlined);
    this->_mainWindow.draw(text_type1);

    sf::Text text_value1;
    text_value1.setFont(this->_font);
    text_value1.setString(m->getMachine());
    text_title.setPosition(coord_x + 30, coord_y);
    text_value1.setCharacterSize(10);
    text_title.setColor(sf::Color::Green);
    this->_mainWindow.draw(text_value1);

    coord_y += 10;
    
    sf::Text text_type2;
    text_type2.setFont(this->_font);
    text_type2.setString("Release: ");
    text_type2.setCharacterSize(10);
    text_title.setPosition(coord_x, coord_y);    
    text_title.setColor(sf::Color::Blue);
    text_title.setStyle(sf::Text::Underlined);
    this->_mainWindow.draw(text_type2);

    sf::Text text_value2;
    text_value2.setFont(this->_font);
    text_value2.setString(m->getRelease());
    text_title.setPosition(coord_x + 30, coord_y);
    text_value2.setCharacterSize(10);
    text_title.setColor(sf::Color::Red);
    this->_mainWindow.draw(text_value2);

    coord_y += 10;
    
    sf::Text text_type3;
    text_type3.setFont(this->_font);
    text_type3.setString("System name: ");
    text_type3.setCharacterSize(10);
    text_title.setPosition(coord_x, coord_y);    
    text_title.setColor(sf::Color::Blue);
    text_title.setStyle(sf::Text::Underlined);
    this->_mainWindow.draw(text_type3);

    sf::Text text_value3;
    text_value3.setFont(this->_font);
    text_value3.setString(m->getSysname());
    text_title.setPosition(coord_x + 30, coord_y);
    text_value3.setCharacterSize(10);
    text_title.setColor(sf::Color::Black);
    this->_mainWindow.draw(text_value3);

}

void	SFMLDisplay::display( Network *m )
{
	(void)m;
	/*
	WINDOW	*local_win;

	m->execute();
	local_win = newwin(this->_height, this->_width, this->_starty, this->_startx);
	box(local_win, 0 , 0);// 0, 0 gives default characters

	start_color();
	init_pair(1, COLOR_RED, COLOR_BLACK);
	init_pair(2, COLOR_BLUE, COLOR_BLACK);
	init_pair(3, COLOR_GREEN, COLOR_BLACK);
	wattron(local_win, COLOR_PAIR(1));
	mvwprintw(local_win, 1, this->_width / 2 -
			  sizeof(m->getTitle().c_str()), m->getTitle().c_str());

	wattron(local_win, COLOR_PAIR(2));
	mvwprintw(local_win, this->_height / 2, 3, "total inbyte: ");
	wattron(local_win, COLOR_PAIR(3));
	mvwprintw(local_win, this->_height / 2, 17, "%Lu", m->getTotalIBytes());

	wattron(local_win, COLOR_PAIR(2));
	mvwprintw(local_win, this->_height / 2 + 1, 3, "total outbyte: ");
	wattron(local_win, COLOR_PAIR(3));
	mvwprintw(local_win, this->_height / 2 + 1, 18, "%Lu", m->getTotalOBytes());

	wrefresh(local_win);
	*/
}

void	SFMLDisplay::display( DateTime *m )
{
	(void)m;
	/*
	WINDOW	*local_win;

	m->execute();
	local_win = newwin(this->_height, this->_width, this->_starty, this->_startx);
	box(local_win, 0 , 0);// 0, 0 gives default characters

	start_color();
	init_pair(1, COLOR_RED, COLOR_BLACK);
	init_pair(2, COLOR_BLUE, COLOR_BLACK);
	init_pair(3, COLOR_GREEN, COLOR_BLACK);
	wattron(local_win, COLOR_PAIR(1));
	mvwprintw(local_win, 1, this->_width / 2 -
			  sizeof(m->getTitle().c_str()), m->getTitle().c_str());

	wattron(local_win, COLOR_PAIR(2));
	mvwprintw(local_win, this->_height / 2, 3, "Date and time: ");
	wattron(local_win, COLOR_PAIR(3));
	mvwprintw(local_win, this->_height / 2, 18, m->getDateTime().c_str());

	wrefresh(local_win);
	*/
}

void	SFMLDisplay::display( HostUserName *m )
{
	(void)m;
	/*
	WINDOW	*local_win;

	m->execute();
	local_win = newwin(this->_height, this->_width, this->_starty, this->_startx);
	box(local_win, 0 , 0);// 0, 0 gives default characters

	start_color();
	init_pair(1, COLOR_RED, COLOR_BLACK);
	init_pair(2, COLOR_BLUE, COLOR_BLACK);
	init_pair(3, COLOR_GREEN, COLOR_BLACK);
	wattron(local_win, COLOR_PAIR(1));
	mvwprintw(local_win, 1, this->_width / 2 -
			  sizeof(m->getTitle().c_str()), m->getTitle().c_str());

	wattron(local_win, COLOR_PAIR(2));
	mvwprintw(local_win, this->_height / 2, 3, "Host name: ");
	wattron(local_win, COLOR_PAIR(3));
	mvwprintw(local_win, this->_height / 2, 14, m->getHostName().c_str());

	wattron(local_win, COLOR_PAIR(2));
	mvwprintw(local_win, this->_height / 2 + 1, 3, "User name: ");
	wattron(local_win, COLOR_PAIR(3));
	mvwprintw(local_win, this->_height / 2 + 1, 14, m->getUserName().c_str());

	wrefresh(local_win);
	*/
}

void	SFMLDisplay::display( CPU *m )
{
	(void)m;
	/*
	WINDOW	*local_win;

	m->execute();
	local_win = newwin(this->_height, this->_width, this->_starty, this->_startx);
	box(local_win, 0 , 0);// 0, 0 gives default characters
	nodelay(local_win, true);

	start_color();
	init_pair(1, COLOR_RED, COLOR_BLACK);
	init_pair(2, COLOR_BLUE, COLOR_BLACK);
	init_pair(3, COLOR_GREEN, COLOR_BLACK);
	wattron(local_win, COLOR_PAIR(1));
	mvwprintw(local_win, 1, this->_width / 2 -
			  sizeof(m->getTitle().c_str()), m->getTitle().c_str());

	wattron(local_win, COLOR_PAIR(2));
	mvwprintw(local_win, this->_height / 2 - 2, 3, "Model: ");
	wattron(local_win, COLOR_PAIR(3));
	mvwprintw(local_win, this->_height / 2 - 2, 10, m->getModel().c_str());

	wattron(local_win, COLOR_PAIR(2));
	mvwprintw(local_win, this->_height / 2 - 1, 3, "Number of cores: ");
	wattron(local_win, COLOR_PAIR(3));
	mvwprintw(local_win, this->_height / 2 - 1, 20, "%d", m->getNbrCores());

	int		len;
	int		i;

	wattron(local_win, COLOR_PAIR(2));
	mvwprintw(local_win, this->_height / 2, 3, "Percentage of CPU idle: ");
	wattron(local_win, COLOR_PAIR(3));
	len = (this->_width - 27) * m->getPCPUIdle();
	for ( i = 0; i < len; ++i )
		mvwprintw(local_win, this->_height / 2, 27 + i, "|");
//	mvwprintw(local_win, this->_height / 2, 27, "%.2f %%", m->getPCPUIdle() * 100);

	wattron(local_win, COLOR_PAIR(2));
	mvwprintw(local_win, this->_height / 2 + 1, 3, "Percentage of CPU system: ");
	wattron(local_win, COLOR_PAIR(3));
	len = (this->_width - 29) * m->getPCPUSys();
	for ( i = 0; i < len; ++i )
		mvwprintw(local_win, this->_height / 2 + 1, 29 + i, "|");
//	mvwprintw(local_win, this->_height / 2 + 1, 29, "%.2f %%", m->getPCPUSys() * 100);

	wattron(local_win, COLOR_PAIR(2));
	mvwprintw(local_win, this->_height / 2 + 2, 3, "Percentage of CPU user: ");
	wattron(local_win, COLOR_PAIR(3));
	len = (this->_width - 27) * m->getPCPUUser();
	for ( i = 0; i < len; ++i )
		mvwprintw(local_win, this->_height / 2 + 2, 27 + i, "|");
//	mvwprintw(local_win, this->_height / 2 + 2, 27, "%.2f %%", m->getPCPUUser() * 100);

	wrefresh(local_win);
	*/
}
///*
void	SFMLDisplay::display( void )
{
	/*
	WINDOW	*local_win;
	char	title[] = "title";
	char	data_type1[] = "data_type1";
	char	data1[] = "data1";
	char	data_type2[] = "data_type2";
	char	data2[] = "data2";
	char	data_type3[] = "data_type3";
	char	data3[] = "data3";

	local_win = newwin(this->_height, this->_width, this->_starty, this->_startx);
	box(local_win, 0 , 0);// 0, 0 gives default characters

	start_color();
	init_pair(1, COLOR_RED, COLOR_BLACK);
	init_pair(2, COLOR_BLUE, COLOR_BLACK);
	init_pair(3, COLOR_GREEN, COLOR_BLACK);
	wattron(local_win, COLOR_PAIR(1));
	mvwprintw(local_win, 1, this->_width / 2 - sizeof(title) / 2, title);

	wattron(local_win, COLOR_PAIR(2));
	mvwprintw(local_win, this->_height / 2 - 1, 3, "%s: ", data_type1);
	wattron(local_win, COLOR_PAIR(3));
	mvwprintw(local_win, this->_height / 2 - 1, 3 + sizeof(data_type1) + 1, data1);

	wattron(local_win, COLOR_PAIR(2));
	mvwprintw(local_win, this->_height / 2, 3, "%s: ", data_type2);
	wattron(local_win, COLOR_PAIR(3));
	mvwprintw(local_win, this->_height / 2, 3 + sizeof(data_type2) + 1, data2);

	wattron(local_win, COLOR_PAIR(2));
	mvwprintw(local_win, this->_height / 2 + 1, 3, "%s: ", data_type3);
	wattron(local_win, COLOR_PAIR(3));
	mvwprintw(local_win, this->_height / 2 + 1, 3 + sizeof(data_type3) + 1, data3);

	wrefresh(local_win);
	*/
}
//*/
