use ChessTournament
/* Konum Konum ilk orada olunmasi gereken saatler*/
select min([Time]) as [Time],[Location]  from Rounds where RoundID in(select RoundID from ChessGames where TournamentId = '0000000001') group by [Location]