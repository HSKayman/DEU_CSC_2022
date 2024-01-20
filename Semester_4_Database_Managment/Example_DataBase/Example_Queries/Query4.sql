Use ChessTournament
go 
/* H ile baslamayan Takimlar Ve Puanlari*/
select TeamName,sum(Point) as Point from (
select ChessTeams.[Name] as TeamName ,sum(case when Table1Point=1 then 1 else 0 end) as Point  from GameScores
inner join ChessGames on
GameScores.ChessGameID=ChessGames.ChessGameID
inner join ChessTeams on
ChessGames.TeamID1=ChessTeams.ChessTeamID
group by ChessTeams.[Name]
Union all
select ChessTeams.[Name] as TeamName,sum(case when Table2Point=1 then 1 else 0 end) as Point from GameScores
inner join ChessGames on
GameScores.ChessGameID=ChessGames.ChessGameID
inner join ChessTeams on
ChessGames.TeamID1=ChessTeams.ChessTeamID
group by ChessTeams.[Name]
Union all
select ChessTeams.[Name] as TeamName,sum(case when Table3Point=1 then 1 else 0 end) as Point  from GameScores
inner join ChessGames on
GameScores.ChessGameID=ChessGames.ChessGameID
inner join ChessTeams on
ChessGames.TeamID1=ChessTeams.ChessTeamID
group by ChessTeams.[Name]
Union all
select ChessTeams.[Name] as TeamName,sum(case when Table4Point=1 then 1 else 0 end) as Point  from GameScores
inner join ChessGames on
GameScores.ChessGameID=ChessGames.ChessGameID
inner join ChessTeams on
ChessGames.TeamID1=ChessTeams.ChessTeamID
group by ChessTeams.[Name]
Union all
select ChessTeams.[Name] as TeamName,sum(case when Table1Point=2 then 1 else 0 end) as Point  from GameScores
inner join ChessGames on
GameScores.ChessGameID=ChessGames.ChessGameID
inner join ChessTeams on
ChessGames.TeamID2=ChessTeams.ChessTeamID
group by ChessTeams.[Name]
Union all
select ChessTeams.[Name] as TeamName,sum(case when Table2Point=2 then 1 else 0 end)  as Point from GameScores
inner join ChessGames on
GameScores.ChessGameID=ChessGames.ChessGameID
inner join ChessTeams on
ChessGames.TeamID2=ChessTeams.ChessTeamID
group by ChessTeams.[Name]
Union all
select ChessTeams.[Name] as TeamName,sum(case when Table3Point=2 then 1 else 0 end) as Point  from GameScores
inner join ChessGames on
GameScores.ChessGameID=ChessGames.ChessGameID
inner join ChessTeams on
ChessGames.TeamID2=ChessTeams.ChessTeamID
group by ChessTeams.[Name]
union all
select ChessTeams.[Name] as TeamName,sum(case when Table4Point=2 then 1 else 0 end) as Point from GameScores
inner join ChessGames on
GameScores.ChessGameID=ChessGames.ChessGameID
inner join ChessTeams on
ChessGames.TeamID2=ChessTeams.ChessTeamID
group by ChessTeams.[Name]
) x group by TeamName having TeamName not like 'H%' order by Point DESC
