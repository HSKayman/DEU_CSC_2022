use ChessTournament
/*Hakemlerin Rutbe siralamasi*/
select [Name],[Rank] from Referees where RefereeID in (select RefereeID from ChessGames where TournamentID in (select TournamentID from Tournaments where TournamentID='0000000001')) order by [Rank] DESC