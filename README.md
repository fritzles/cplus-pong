# beer-pong
CS120 Final Project

Jordan Guzak
Michael Fritz
Chris Bratkovics

Classes:
	Player
		String Name
		Int gamesPlayed
		Int gamesWon
		
		Save data()
		Load data()
		
	Agent abstract class for Paddle and Ball
		X coordinate
		Y coordinate
		Color
		Change color
	
	Paddle inherits Agent
		Int points
		Int length
		
	Ball inherits agent
		X cord
		Y cord
		angle
		Speed
	
	Field has Agents
		Int height
		Int width
	
	Game has a Field, Ball, 2 Players
		Field field
		Paddle left
		Paddle right
		
		updateScore(Paddle)
		
		
		checkContact()
			Checks the ball coordinates and calls smaller collision detection functions
		
		setBallSpeed()
		setBallAngle()
		setBallCoordinates()
		
	
		
Stretch goals:
	Changeable colors for players, ball, field
	Alternative physics
	Games based on timer, with support for keeping track of lifetime points scored
	Four player mode

