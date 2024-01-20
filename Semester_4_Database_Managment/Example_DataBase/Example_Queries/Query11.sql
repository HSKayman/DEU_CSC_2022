use ChessTournament
/* ilk turnuvada rakip takimlar, saat ve Hakemler*/
select 
coalesce((select ChessTeams.[Name] from ChessTeams where ChessTeams.ChessTeamID = ChessGames.TeamID1), '-') "Team Name 1",
coalesce((select ChessTeams.[Name] from ChessTeams where ChessTeams.ChessTeamID = ChessGames.TeamID2), '-') "Team Name 2",
Referees.[Name]
from ChessGames
  inner join ChessTeams on ChessTeams.ChessTeamID=ChessGames.TeamID1
  inner join Referees on Referees.RefereeID=ChessGames.RefereeID
where ChessGames.RoundID in 
(select RoundID from Rounds where [Time]=(select min([Time]) from Rounds)) 