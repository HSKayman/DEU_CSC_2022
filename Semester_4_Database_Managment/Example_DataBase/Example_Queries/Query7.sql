use ChessTournament
go

/*Grady nin Yonettigi Maclarin Oyunculari*/
select * from ChessPlayers where ChessTeamID in (select ChessTeamID from ChessTeams where ChessTeamID in

(select TeamID1  from ChessGames where RefereeID in
(select RefereeID from Referees where [Name]='Grady'))
or 
ChessTeamID in(select TeamID2  from ChessGames where RefereeID in
(select RefereeID from Referees where [Name]='Grady'))) order by ELO DESC
