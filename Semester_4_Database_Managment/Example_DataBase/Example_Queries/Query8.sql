use ChessTournament
/*Takimlarin En Iyi Elolularin ELOsu ve Takimin Ismi*/
select ChessTeams.[Name] ,max(ChessPlayers.ELO) as ELO from ChessTeams 
inner join ChessPlayers on ChessPlayers.ChessTeamID=ChessTeams.ChessTeamID group by ChessTeams.Name order by ELO DESC