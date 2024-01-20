use ChessTournament
go

/*Round1 e Gelecek Takimlarin Isimleriyle Sloganlari slogansizlar elensin ama*/
select [Name], Slogan from ChessTeams where ChessTeamID in(select TeamID1 from ChessGames where RoundID in (select RoundID from Rounds where RoundID='0000000001') 
	union 
select TeamID2 from ChessGames where RoundID in (select RoundID from Rounds where RoundID='0000000001'))
