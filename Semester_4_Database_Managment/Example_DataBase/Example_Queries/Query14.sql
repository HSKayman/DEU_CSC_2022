use ChessTournament
/*Takimlarin Kaptan iceren pozisyona sahip oyuncularin isimleri soyisimleri ve takimlari*/
select ChessTeams.[Name], ChessPlayers.[Name],ChessPlayers.Surname, ChessPlayers.Position from ChessPlayers
inner join ChessTeams on ChessPlayers.ChessTeamID=ChessTeams.ChessTeamID
where ChessPlayers.Position like'%captain%' and ChessPlayers.ELO>2000