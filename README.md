# beer-pong
CS120 Final Project

<<<<<<< HEAD
Jordan Guzak
Michael Fritz
Chris Bratkovics

Core classes:
	Player
		String Name
		Int gamesPlayed
		Int gamesWon
		
		Save data(Player)
		Load data()
		
	Agent abstract class for Paddle and Ball
		Int X coordinate
		Int Y coordinate
		Struct Color
		
		Pure virtual move()
		
		setColor()
		getY()
		getX()
		getColor()
	
	Paddle inherits Agent
		Int points
		Int length
		
		Override move()
		
		getPoints()
		getLength()
		
	Ball inherits agent
		Int angle
		Int speed
		
		Override move()
	
	Field has Agents
		Int height
		Int width
		Struct color
		
		getHeight()
		getWidth()
		getColor()
		
		displayField()
	
	Game has a Field, Ball, 2 Players
		Field gameField
		Ball gameBall
		Paddle leftPaddle
		Paddle rightPaddle
		Player player1
		Player player2
		
		checkContact() Checks the ball coordinates and calls smaller collision detection functions
		
		setBallSpeed()
		setBallAngle()
		setBallCoordinates()
		
		updateScore(Paddle)
		checkScore()
		updatePlayerStats()

		
	
		
Stretch goals:
	Changeable colors for players, ball, field
	Alternative physics
	Games based on timer, with support for keeping track of lifetime points scored
	Four player mode
	Custom ball textures

=======

Sick Dank Nasty
>>>>>>> origin/master
