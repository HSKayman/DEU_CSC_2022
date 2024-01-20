use ChessTournament
/* Okulda Oynanacak Oyunlarin oyuncularin */ 
select ChessPlayers.[Name]
from ChessPlayers
inner join
(select TeamID1 as Team from ChessGames where RoundID in (select RoundID from Rounds where [Location]='School')
union
select TeamID2 as Team from ChessGames where RoundID in (select RoundID from Rounds where [Location]='School'))X 
on X.Team=ChessPlayers.ChessTeamID


