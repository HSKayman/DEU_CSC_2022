use ChessTournament 
/*hangi takimin kac defa takim 1 oldugu*/
select ChessTeams.[Name], count(1) as Team1Teams from ChessGames 
inner join ChessTeams on ChessTeams.ChessTeamID=ChessGames.TeamID1
group by ChessTeams.Name