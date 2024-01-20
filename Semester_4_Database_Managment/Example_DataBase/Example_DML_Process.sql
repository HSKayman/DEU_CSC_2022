use [ChessTournament]
go
/* Yeni Tablolar*/
CREATE TABLE [dbo].[GameScores](
	[ChessGameID] [char](10) NOT NULL,
	[Table1Point] [tinyint] NOT NULL,
	[Table2Point] [tinyint] NOT NULL,
	[Table3Point] [tinyint] NOT NULL,
	[Table4Point] [tinyint] NOT NULL,
 CONSTRAINT [PK_GameScores] PRIMARY KEY CLUSTERED 
([ChessGameID] ASC)WITH (PAD_INDEX = OFF, STATISTICS_NORECOMPUTE = OFF, IGNORE_DUP_KEY = OFF, ALLOW_ROW_LOCKS = ON, ALLOW_PAGE_LOCKS = ON) ON [PRIMARY]) ON [PRIMARY]
go
CREATE TABLE [dbo].[Notations](
	[ChessGameID] [char](10) NOT NULL,
	[Table1] [nvarchar](100) NULL,
	[Table2] [nvarchar](100) NULL,
	[Table3] [nvarchar](100) NULL,
	[Table4] [nvarchar](100) NULL,
 CONSTRAINT [PK_Rotations] PRIMARY KEY CLUSTERED 
([ChessGameID] ASC
)WITH (PAD_INDEX = OFF, STATISTICS_NORECOMPUTE = OFF, IGNORE_DUP_KEY = OFF, ALLOW_ROW_LOCKS = ON, ALLOW_PAGE_LOCKS = ON) ON [PRIMARY]) ON [PRIMARY]
GO
/*Baglantilar*/
ALTER TABLE [dbo].[GameScores]  WITH CHECK ADD  CONSTRAINT [FK_GameScores_ChessGames] FOREIGN KEY([ChessGameID])
REFERENCES [dbo].[ChessGames] ([ChessGameID])
GO
ALTER TABLE [dbo].[GameScores] CHECK CONSTRAINT [FK_GameScores_ChessGames]
GO
ALTER TABLE [dbo].[GameScores]  WITH CHECK ADD  CONSTRAINT [FK_GameScores_Rotations] FOREIGN KEY([ChessGameID])
REFERENCES [dbo].[Notations] ([ChessGameID])
GO
ALTER TABLE [dbo].[GameScores] CHECK CONSTRAINT [FK_GameScores_Rotations]
GO

/*Yeni Takim Katildi */
INSERT [dbo].[ChessTeams] ([ChessTeamID], [Name], [Country], [Slogan]) VALUES (N'0000000008', N'Odin', N'Findland', N'Well All is')
go
INSERT [dbo].[ChessPlayers] ([ChessPlayersID], [ChessTeamID], [Name], [Surname], [Position], [TableNo], [ELO]) VALUES (N'0000000029', N'0000000008', N'Kory', N'Vargas', N'Captain', 1, 2467)
INSERT [dbo].[ChessPlayers] ([ChessPlayersID], [ChessTeamID], [Name], [Surname], [Position], [TableNo], [ELO]) VALUES (N'0000000030', N'0000000008', N'Chelsea', N'Barton', N'Cr Captain', 2, 2765)
INSERT [dbo].[ChessPlayers] ([ChessPlayersID], [ChessTeamID], [Name], [Surname], [Position], [TableNo], [ELO]) VALUES (N'0000000031', N'0000000008', N'Saoirse', N'Battle', N'Member', 3, 2765)
INSERT [dbo].[ChessPlayers] ([ChessPlayersID], [ChessTeamID], [Name], [Surname], [Position], [TableNo], [ELO]) VALUES (N'0000000033', N'0000000008', N'Abbiden', N'Busher', N'Member', 5, 2846)
INSERT [dbo].[ChessPlayers] ([ChessPlayersID], [ChessTeamID], [Name], [Surname], [Position], [TableNo], [ELO]) VALUES (N'0000000032', N'0000000008', N'Abbi', N'Bush', N'Member', 4, 2846)
go
INSERT [dbo].[ChessGames] ([ChessGameID], [TournamentID], [RefereeID], [RoundID], [TeamID1], [TeamID2]) VALUES (N'0000000008', N'0000000002', N'0000000005', N'0000000004', N'0000000007', N'0000000008')
INSERT [dbo].[ChessGames] ([ChessGameID], [TournamentID], [RefereeID], [RoundID], [TeamID1], [TeamID2]) VALUES (N'0000000010', N'0000000002', N'0000000003', N'0000000005', N'0000000005', N'0000000008')
INSERT [dbo].[ChessGames] ([ChessGameID], [TournamentID], [RefereeID], [RoundID], [TeamID1], [TeamID2]) VALUES (N'0000000011', N'0000000002', N'0000000002', N'0000000006', N'0000000006', N'0000000008')
go

/*Macda Elolar Yanlis Girilmstiir minimum 2000 olmasi gerekiyordur hocalar hile yaparak 2000 den kucukleri 2000 e cakmistir*/
update ChessPlayers set ELO = 2000 where ELO<2000
go

/*Kacak Oyuncu Tespit edilip silinmistir*/
delete from [dbo].[ChessPlayers] where ChessPlayersID='0000000033'
go

/*Maclarin Hepsi Bitti Sonuclar Veritabanima Islenecek*/
INSERT [dbo].[Notations] ([ChessGameID], [Table1], [Table2], [Table3], [Table4]) VALUES (N'0000000001', N'e2-e4 e7-e5', NULL, NULL, NULL)
INSERT [dbo].[Notations] ([ChessGameID], [Table1], [Table2], [Table3], [Table4]) VALUES (N'0000000002', NULL, N'Ng1-f3 Nb8-c6', NULL, NULL)
INSERT [dbo].[Notations] ([ChessGameID], [Table1], [Table2], [Table3], [Table4]) VALUES (N'0000000003', NULL, NULL, N'	Bf1-b5 a7-a6', NULL)
INSERT [dbo].[Notations] ([ChessGameID], [Table1], [Table2], [Table3], [Table4]) VALUES (N'0000000004', NULL, NULL, NULL, N'Bb5xNc6 d7xBc6')
INSERT [dbo].[Notations] ([ChessGameID], [Table1], [Table2], [Table3], [Table4]) VALUES (N'0000000005', NULL, NULL, N'd2-d3 Bf8-b4+', NULL)
INSERT [dbo].[Notations] ([ChessGameID], [Table1], [Table2], [Table3], [Table4]) VALUES (N'0000000006', NULL, N'Nb1-c3 Ng8-f6', NULL, NULL)
INSERT [dbo].[Notations] ([ChessGameID], [Table1], [Table2], [Table3], [Table4]) VALUES (N'0000000007', N'0-0 Bb4xNc3', NULL, NULL, NULL)
INSERT [dbo].[Notations] ([ChessGameID], [Table1], [Table2], [Table3], [Table4]) VALUES (N'0000000008', NULL, NULL, NULL, NULL)
INSERT [dbo].[Notations] ([ChessGameID], [Table1], [Table2], [Table3], [Table4]) VALUES (N'0000000009', NULL, NULL, NULL, NULL)
INSERT [dbo].[Notations] ([ChessGameID], [Table1], [Table2], [Table3], [Table4]) VALUES (N'0000000010', NULL, NULL, NULL, NULL)
INSERT [dbo].[Notations] ([ChessGameID], [Table1], [Table2], [Table3], [Table4]) VALUES (N'0000000011', NULL, NULL, NULL, NULL)
INSERT [dbo].[Notations] ([ChessGameID], [Table1], [Table2], [Table3], [Table4]) VALUES (N'0000000012', NULL, NULL, NULL, NULL)
go
/*Table1Point de 1 yaziyorsa 1 numarali Takim, 2 yaziyorsa 2 numarali takim kazanmistir, 0 yaziyor iste berabere anlamina gelir*/
INSERT [dbo].[GameScores] ([ChessGameID], [Table1Point], [Table2Point], [Table3Point], [Table4Point]) VALUES (N'0000000001', 1, 2, 0, 1)
INSERT [dbo].[GameScores] ([ChessGameID], [Table1Point], [Table2Point], [Table3Point], [Table4Point]) VALUES (N'0000000002', 2, 1, 1, 1)
INSERT [dbo].[GameScores] ([ChessGameID], [Table1Point], [Table2Point], [Table3Point], [Table4Point]) VALUES (N'0000000003', 1, 1, 1, 1)
INSERT [dbo].[GameScores] ([ChessGameID], [Table1Point], [Table2Point], [Table3Point], [Table4Point]) VALUES (N'0000000004', 2, 1, 2, 2)
INSERT [dbo].[GameScores] ([ChessGameID], [Table1Point], [Table2Point], [Table3Point], [Table4Point]) VALUES (N'0000000005', 2, 2, 2, 2)
INSERT [dbo].[GameScores] ([ChessGameID], [Table1Point], [Table2Point], [Table3Point], [Table4Point]) VALUES (N'0000000006', 1, 1, 0, 0)
INSERT [dbo].[GameScores] ([ChessGameID], [Table1Point], [Table2Point], [Table3Point], [Table4Point]) VALUES (N'0000000007', 0, 0, 1, 0)
INSERT [dbo].[GameScores] ([ChessGameID], [Table1Point], [Table2Point], [Table3Point], [Table4Point]) VALUES (N'0000000009', 1, 1, 1, 1)
INSERT [dbo].[GameScores] ([ChessGameID], [Table1Point], [Table2Point], [Table3Point], [Table4Point]) VALUES (N'0000000012', 2, 2, 2, 2)
INSERT [dbo].[GameScores] ([ChessGameID], [Table1Point], [Table2Point], [Table3Point], [Table4Point]) VALUES (N'0000000010', 2, 2, 2, 2)
INSERT [dbo].[GameScores] ([ChessGameID], [Table1Point], [Table2Point], [Table3Point], [Table4Point]) VALUES (N'0000000011', 1, 1, 1, 1)
INSERT [dbo].[GameScores] ([ChessGameID], [Table1Point], [Table2Point], [Table3Point], [Table4Point]) VALUES (N'0000000008', 1, 2, 2, 1)
go