use ChessTournament
/*Notasyonlari olmayan Maclarin ID si*/
select ChessGames.ChessGameID from Notations
inner join ChessGames on ChessGames.ChessGameID=Notations.ChessGameID
inner join ChessPlayers on ChessPlayers.ChessTeamID=ChessGames.TeamID1 or 
ChessPlayers.ChessTeamID=ChessGames.TeamID2 where Notations.Table1 is NUll and 
ChessPlayers.TableNo=1 
union
select ChessGames.ChessGameID from Notations
inner join ChessGames on ChessGames.ChessGameID=Notations.ChessGameID
inner join ChessPlayers on ChessPlayers.ChessTeamID=ChessGames.TeamID1 or 
ChessPlayers.ChessTeamID=ChessGames.TeamID2 where Notations.Table2 is NUll and 
ChessPlayers.TableNo=2 
union 
select ChessGames.ChessGameID from Notations
inner join ChessGames on ChessGames.ChessGameID=Notations.ChessGameID
inner join ChessPlayers on ChessPlayers.ChessTeamID=ChessGames.TeamID1 or 
ChessPlayers.ChessTeamID=ChessGames.TeamID2 where Notations.Table3 is NUll and 
ChessPlayers.TableNo=3
union
select ChessGames.ChessGameID from Notations
inner join ChessGames on ChessGames.ChessGameID=Notations.ChessGameID
inner join ChessPlayers on ChessPlayers.ChessTeamID=ChessGames.TeamID1 or 
ChessPlayers.ChessTeamID=ChessGames.TeamID2 where Notations.Table4 is NUll and 
ChessPlayers.TableNo=4
