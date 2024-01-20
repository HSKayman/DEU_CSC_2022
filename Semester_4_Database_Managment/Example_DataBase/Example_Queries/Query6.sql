use ChessTournament
/* Oyuncular Ve Kazandigi Mac Adeti*/
select [Name],sum(Point) as Point from (
select ChessPlayers.[Name],sum(case when GameScores.Table1Point=1 then 1 else 0 end) as Point  from ChessPlayers 
inner join ChessTeams on ChessPlayers.ChessTeamID=ChessTeams.ChessTeamID
inner join ChessGames on ChessGames.TeamID1=ChessTeams.ChessTeamID  
inner join GameScores on ChessGames.ChessGameID=GameScores.ChessGameID where ChessPlayers.TableNo=1 group by ChessPlayers.[Name] 
union 
select ChessPlayers.[Name],sum(case when GameScores.Table2Point=1 then 1 else 0 end) as Point  from ChessPlayers 
inner join ChessTeams on ChessPlayers.ChessTeamID=ChessTeams.ChessTeamID
inner join ChessGames on ChessGames.TeamID1=ChessTeams.ChessTeamID  
inner join GameScores on ChessGames.ChessGameID=GameScores.ChessGameID where ChessPlayers.TableNo=2 group by ChessPlayers.[Name] 
union 
select ChessPlayers.[Name],sum(case when GameScores.Table3Point=1 then 1 else 0 end) as Point  from ChessPlayers 
inner join ChessTeams on ChessPlayers.ChessTeamID=ChessTeams.ChessTeamID
inner join ChessGames on ChessGames.TeamID1=ChessTeams.ChessTeamID  
inner join GameScores on ChessGames.ChessGameID=GameScores.ChessGameID where ChessPlayers.TableNo=3 group by ChessPlayers.[Name] 
union 
select ChessPlayers.[Name],sum(case when GameScores.Table4Point=1 then 1 else 0 end) as Point  from ChessPlayers 
inner join ChessTeams on ChessPlayers.ChessTeamID=ChessTeams.ChessTeamID
inner join ChessGames on ChessGames.TeamID1=ChessTeams.ChessTeamID  
inner join GameScores on ChessGames.ChessGameID=GameScores.ChessGameID where ChessPlayers.TableNo=4 group by ChessPlayers.[Name] 
union
select ChessPlayers.[Name],sum(case when GameScores.Table1Point=2 then 1 else 0 end) as Point  from ChessPlayers 
inner join ChessTeams on ChessPlayers.ChessTeamID=ChessTeams.ChessTeamID
inner join ChessGames on ChessGames.TeamID2=ChessTeams.ChessTeamID  
inner join GameScores on ChessGames.ChessGameID=GameScores.ChessGameID where ChessPlayers.TableNo=1 group by ChessPlayers.[Name] 
union 
select ChessPlayers.[Name],sum(case when GameScores.Table2Point=2 then 1 else 0 end) as Point  from ChessPlayers 
inner join ChessTeams on ChessPlayers.ChessTeamID=ChessTeams.ChessTeamID
inner join ChessGames on ChessGames.TeamID2=ChessTeams.ChessTeamID  
inner join GameScores on ChessGames.ChessGameID=GameScores.ChessGameID where ChessPlayers.TableNo=2 group by ChessPlayers.[Name] 
union 
select ChessPlayers.[Name],sum(case when GameScores.Table3Point=2 then 1 else 0 end) as Point  from ChessPlayers 
inner join ChessTeams on ChessPlayers.ChessTeamID=ChessTeams.ChessTeamID
inner join ChessGames on ChessGames.TeamID2=ChessTeams.ChessTeamID  
inner join GameScores on ChessGames.ChessGameID=GameScores.ChessGameID where ChessPlayers.TableNo=3 group by ChessPlayers.[Name] 
union 
select ChessPlayers.[Name],sum(case when GameScores.Table4Point=2 then 1 else 0 end) as Point from ChessPlayers 
inner join ChessTeams on ChessPlayers.ChessTeamID=ChessTeams.ChessTeamID
inner join ChessGames on ChessGames.TeamID2=ChessTeams.ChessTeamID  
inner join GameScores on ChessGames.ChessGameID=GameScores.ChessGameID where ChessPlayers.TableNo=4 group by ChessPlayers.[Name] 

)X Group by [Name] order by Point DESC