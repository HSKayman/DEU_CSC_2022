use ChessTournament 
/*Hakemlerin is yuku*/
select Referees.[Name],count(ChessGames.RefereeID) as NumberOfChessGame from ChessGames 
inner join Referees on Referees.RefereeID=ChessGames.RefereeID group by Referees.[Name]