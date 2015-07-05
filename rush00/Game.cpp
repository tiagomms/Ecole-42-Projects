#include "Game.hpp"

int Game::_CreateEnemyDelay = 10;
int Game::_time = 10;
int Game::_enemyFleetSize = 0;
int Game::_playerFleetSize = 0;
const int Game::_EnemiesMax = 20;

Game::Game()
{
	WINDOW* win = initscr();
	nodelay(stdscr, true); //getch not wait until the user press a key 
	keypad(stdscr, true);
	noecho();
	curs_set(0);
	getmaxyx(stdscr, this->_maxheight, this->_maxwidth);

	this->buildEnemyTab();
	this->_player = PlayerShip( this->_maxwidth / 2, this->_maxheight / 2);
	Game::_playerFleetSize++;

	this->_points = 0;
	this->_delay = 110000;

	this->_direction = 'r';
	srand(time(0));
//	putenemy();

//	for(unsigned long i = 0; i<ship.size();++i)
	// {
	// 	move(ship[i].y, ship[i].x);
	// 	addch(_partchar);
	// }
//	move(_maxheight-1, 0);
//	printw("%d", __points);
//	move(enemy.y, enemy.x);
//	addch(enem);
//	refresh();
	start(win);
}

Game::~Game()
{
	//delete [] this->_enemies;
	nodelay(stdscr, false);
	getch();
	endwin();
}

/*
void				Game::updateIndex(AVaisseau *type)
{
	int index = 0;
	AVaisseau * ship = type;
	while (ship)
	{
		ship->setIndex(index);
		index++;
		ship = ship->getNext();
	}
}
*/

AVaisseau			Game::getEnemyByIndex(int index) const
{
	return (this->_enemies)[index];
}


void				Game::deleteEnemyByIndex(int index)
{
	this->_enemies[index] = Enemy();
	Game::_enemyFleetSize--;
}


bool Game::doCollide(AVaisseau & ship1, AVaisseau & ship2)
{
	int i;
	int j;

	i = 0;
	while(i < ship2.getTailleX())
	{
		j = 0;
		while (j < ship2.getTailleY())
		{
			if((ship2.getX() + j >= ship1.getX()
			 && ship2.getX() + j <= ship1.getX() + ship1.getTailleX())
				&& (ship2.getY() + i >= ship1.getY() 
					&& ship2.getY() + i <= ship1.getY() + ship1.getTailleY()))
        		return true;
			j++;        	
		}
		i++;
	}
    return false;
}

bool Game::insideWall(AVaisseau & ship)
{
    if((ship.getX() > 0 && ship.getX() + ship.getTailleX() < this->_maxwidth) &&
        (ship.getY() > 0 && ship.getY() + ship.getTailleY() < this->_maxheight - 1))
        return true;
    return false;	
}

bool Game::playerCollide()
{
    int i;

    i = 0;
    if (!insideWall(this->_player))
    	return true;
    while (i < Game::_EnemiesMax)
    {
        if (this->getEnemy(i).getEActivated())
        {
            if(doCollide(this->_player, this->getEnemy(i)))
            {
                return true;
            }
        }
        i++;
    }
    return false;
}


AVaisseau	&	Game::getEnemy(int index) const
{
	return this->_enemies[index];
}

Game & Game::operator=(Game const & src)
{
    this->_points = src._points;
    this->_delay = src._delay;
    this->_maxwidth = src._maxwidth;
    this->_maxheight = src._maxheight;
    this->_direction = src._direction;
    this->_enemies = src._enemies;//?
    
    this->_CreateEnemyDelay = src._CreateEnemyDelay;
    this->_time = src._time;
    this->_enemyFleetSize = src._enemyFleetSize;
    this->_playerFleetSize = src._playerFleetSize;
    return *this;    
} // Canonical


Game::Game(Game const & src)
{
    *this = src;
    return;
} //Canonical


void Game::movePlayer(AVaisseau  & player)
{
	int stepx;
	int stepy;
	int i = 0;
	int j = 0;
	//detect key
	int tmp = getch();
	switch(tmp)
	{
		case KEY_LEFT:
			stepx = -2;
			stepy = 0;
//		player.setVitesseX(player.getVitesseX() - 2);
		if(_direction == 'r' && player.getVitesseX() + stepx > 0)
			break;
		_direction='l';
			break;
		case KEY_UP:
			stepy = -1;
			stepx = 0;
//			player.setVitesseY(player.getVitesseY() - 1);
		if(_direction == 'd' && player.getVitesseY() + stepy > 0)
			break;
		_direction='u';
			break;
		case KEY_DOWN:
			stepy = 1;
			stepx = 0;
//			player.setVitesseY(player.getVitesseY() + 1);
		if(_direction == 'u' && player.getVitesseY() + stepy < 0)
			break;
		_direction='d';
			break;
		case KEY_RIGHT:
			stepx = 2;
			stepy = 0;
//			player.setVitesseX(player.getVitesseX() + 2);
		if(_direction == 'l' && player.getVitesseX() + stepx < 0)
			break;
		_direction='r';
			break;
		case 27:
			stepx = 0;
			stepy = 0;
			_direction='q';
		break;
		case ' ':
		{
			stepx = 0;
			stepy = 0;
			player.addMissile();
			break;
		}
		default:
			stepx = 0;
			stepy = 0;
			break;

	}
	while (stepx != 0 || stepy != 0)
	{
		player.setVitesseX(player.getVitesseX() + (stepx % 2));
		player.setVitesseY(player.getVitesseY() + (stepy % 2));
		if (_direction=='l')
			player.changePosition(player.getX() + player.getVitesseX() , player.getY() + player.getVitesseY());
		else if(_direction=='r')
			player.changePosition(player.getX() + player.getVitesseX() , player.getY() + player.getVitesseY());
		else if(_direction=='u')
			player.changePosition(player.getX() + player.getVitesseX() , player.getY() + player.getVitesseY() + player.getVitesseY());		
		else if(_direction=='d')
			player.changePosition(player.getX() + player.getVitesseX() , player.getY() + player.getVitesseY() + player.getVitesseY());

		//playerCollide
		stepx = (stepx != 0 ? (stepx < 0 ? ++stepx: --stepx) : 0);
		stepy = (stepy != 0 ? (stepy < 0 ? ++stepy: --stepy) : 0);		
	}
	this->moveMissilesFromShip(player);
	while ( i < player.getTailleX())
    {
        while(j < player.getTailleY())
        {
            mvwprintw(stdscr, player.getY() + player.getVitesseY()+j,player.getX() + player.getVitesseX() + i ,"%c", player.getBordersChar());
            ++j;
        }
        j = 0;
        ++i;
        refresh();
    }
}

Missile		&	Game::getMissileByIndex(AVaisseau & ship, int index)
{
	return ship.getMissile(index);
}


void			Game::deleteMissileByIndex(AVaisseau & ship, int index)
{
	ship.deleteMissile(index);
}

void		Game::createMissile(AVaisseau & ship)
{
	ship.addMissile();
}

void Game::moveFleet()
{
	int i;

	i = 0;
	if (!Game::_enemyFleetSize)
		return;
	while (i < Game::_EnemiesMax)
	{
		if (this->getEnemy(i).getEActivated())
		{
			this->getEnemy(i).changePosition(this->getEnemy(i).getX(), this->getEnemy(i).getY() + this->getEnemy(i).getShootingDir());
			move(this->getEnemy(i).getY(), this->getEnemy(i).getX());
			addch(this->getEnemy(i).getBordersChar()); //borderchar
		}
		i++;
	}
	refresh();
}

void Game::moveMissilesFromShip(AVaisseau & ship)
{
	int i;

	i = 0;
	while (i < ship.getMissileMax())
	{
		if (ship.getMissile(i).getActivated())
		{
			ship.getMissile(i).changePosition(ship.getMissile(i).getX(), 
									ship.getMissile(i).getY() + ship.getMissile(i).getVitesseY());
			move(ship.getMissile(i).getY(), ship.getMissile(i).getX());
			addch(ship.getMissileChar());
		}
		i++;
	}
}

void Game::CreateEnemy()
{
	int i;

	i = 0;
	if (!Game::_enemyFleetSize)
	{
		this->_enemies[0] = Enemy((rand() % this->_maxwidth) + 1, 0);
		Game::_enemyFleetSize++;	
		return;
	}
	if (Game::_enemyFleetSize >= Game::_EnemiesMax)
		return;
	Game::_time -= 1;
	if (Game::_time == 0)
	{
		while (i < Game::_EnemiesMax)
		{
			if (!this->getEnemy(i).getEActivated())
			{
				this->_enemies[i] = Enemy((rand() % this->_maxwidth) + 1, 0);
				Game::_enemyFleetSize++;
				return;
			}
			i++;
		}
	}
}

void	Game::buildEnemyTab()
{
	int i;

	this->_enemies = new Enemy[Game::_EnemiesMax];
	i = Game::_EnemiesMax - 1;
	while (i)
	{
		this->_enemies[i] = Enemy();
		i--;
	}
}


void Game::start( WINDOW *win)
{
	double    tmp;
    double    chrono;
    tmp = time(NULL);
    while(1)
    {
        getmaxyx(stdscr, this->_maxheight, this->_maxwidth);
        erase();
        wborder(win, '|', '|',' ', ' ', '|', '|', '|', '|');
        mvwprintw(win, this->_maxheight - 1, 1 ,"SCORE : %d", this->_points);
        mvwprintw(win, this->_maxheight - 1, this->_maxwidth/2 ,"Life : %d", this->_player.getLives());
        chrono = time(NULL) - tmp;
        mvwprintw(win, 0, 1 ,"TIME : %g", chrono);
        wrefresh(win);
        

        CreateEnemy();
        /**COLOR**/
        start_color();
        init_pair(3,COLOR_BLACK, COLOR_WHITE);        
        wbkgd(stdscr,COLOR_PAIR(3));

        init_pair(1,COLOR_BLUE,COLOR_BLUE);
        attron(COLOR_PAIR(1));
        movePlayer(this->_player);
        attroff(COLOR_PAIR(1));

        init_pair(2,COLOR_RED,COLOR_RED);
        attron(COLOR_PAIR(2));
        moveFleet();
        attroff(COLOR_PAIR(1));
        if(playerCollide())
        {
            move(this->_maxheight/2, this->_maxwidth/2);
            printw("game over");
            break;
        }        
        if(_direction=='q')
        {    
            init_pair(1,COLOR_WHITE,COLOR_WHITE);
            init_pair(2,COLOR_WHITE,COLOR_WHITE);
            break;
        }
        
        usleep(_delay);
    }
}