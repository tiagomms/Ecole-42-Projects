// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   SFMLDisplay.hpp                                  :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: lperrigu <marvin@42.fr>                    +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2015/06/27 19:21:54 by lperrigu          #+#    #+#             //
//   Updated: 2015/06/28 14:11:45 by lperrigu         ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#ifndef SFMLDISPLAY_HPP
#define SFMLDISPLAY_HPP

#include "IMonitorDisplay.hpp"
#include "RAM.hpp"
#include "OSInfo.hpp"
#include "Network.hpp"
#include "DateTime.hpp"
#include "HostUserName.hpp"
#include "CPU.hpp"
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <list>
#include <algorithm>


class RAM;
class OSInfo;
class Network;
class DateTime;
class HostUserName;
class CPU;

class SFMLDisplay : public IMonitorDisplay
{
public:
	SFMLDisplay( void );
	virtual ~SFMLDisplay( void );
	SFMLDisplay( int width, int height, int startx, int starty,
				   IMonitorModule *mod );
	SFMLDisplay( SFMLDisplay const & );

	void	display( void );
	void	display( OSInfo * );
	void	display( RAM * );
	void	display( Network * );
	void	display( DateTime * );
	void	display( HostUserName * );
	void	display( CPU * );
	void	refresh( void );
	void	run(void);

private:
	int					_width;
	int					_height;
	int					_startx;
	int					_starty;
	IMonitorModule		*_mod;
	sf::RenderWindow 	_mainWindow;
	sf::Texture			_mainTexture;
	sf::Font			_font;
	sf::Texture			_spriteTexture;


	SFMLDisplay& operator=( SFMLDisplay const & );

};


#endif

/*

void GraphicDisplay::drawModuleSkin(std::string moduleName, int nRows) {
   sf::Sprite sprite;
   sprite.setTexture(this->_headerTexture);
   sprite.setColor(sf::Color(255, 255, 255, 160));
   sprite.setPosition(0, this->_shiftModule);
   this->_mainWindow.draw(sprite);

   sf::Text text;
   text.setFont(this->_arial);
   text.setString(moduleName);
   text.setCharacterSize(14);
   int centerWidth = WIDTH / 2 - text.getGlobalBounds().width / 2;
   text.setPosition(centerWidth, this->_shiftModule + 7);
   text.setColor(sf::Color::White);
   text.setStyle(sf::Text::Bold | sf::Text::Underlined);

   this->_mainWindow.draw(text);
   this->_shiftModule = this->_shiftModule + this->_headerTexture.getSize().y;
   this->_headerShift = this->_shiftModule;

   sf::Sprite spritePanel;
   spritePanel.setTexture(this->_contentTexture);
   spritePanel.setScale(1.0f, nRows / 2.0f);
   spritePanel.setColor(sf::Color(64, 167, 177, 255));
   spritePanel.setPosition(0, this->_shiftModule);
   this->_mainWindow.draw(spritePanel);

   this->_shiftModule =
           this->_shiftModule + spritePanel.getGlobalBounds().height;
}




*/