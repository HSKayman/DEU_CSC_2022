use ChessTournament
/*ELOsu 2000-3000 arasindaki sahip olan Takimlarin Isimleriyle Memleketleri */
select DISTINCT ChessTeams.[Name], ChessTeams.[Country] from ChessTeams
inner join ChessPlayers on ChessPlayers.ChessTeamID=ChessTeams.ChessTeamID
where ChessPlayers.ELO BETWEEN 2000 and 3000