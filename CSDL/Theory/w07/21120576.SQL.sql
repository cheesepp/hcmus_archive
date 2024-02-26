--Cau 1 Cho biết số lần các cặp đội thi đấu cùng nhau 
select count(td1.MaTD) as Sotrandau, td1.Madoi1, td1.MaDoi2
from TRANDAU td1 left join TRANDAU td2 on td1.MaDoi1=td2.MaDoi2 and td1.MaDoi2=td2.MaDoi1  
where td2.MaDoi1 is null
group by td1.Madoi1, td1.Madoi2
union
select count(td1.MaTD) as Sotrandau, least(td1.Madoi1,td1.MaDoi2) as Doi1, greatest(td2.Madoi1,td2.MaDoi2) as Doi2
from TRANDAU td1 join TRANDAU td2 on td1.MaDoi1=td2.MaDoi2 and td1.MaDoi2=td2.MaDoi1  
group by least(td1.Madoi1,td1.Madoi2), greatest(td2.Madoi1,td2.Madoi2)

--Cau 2 Cho biết số trận đấu diễn ra tại mỗi sân vận động
select  td.SanVD, count(td.MaTD) as Sotran
from TRANDAU td
group by td.SanVD
--Cau 3 Cho biết sân vận động nào diễn ra nhiều trận đấu nhất
select  td.SanVD ,count(td.MaTD) as Sotrandau
from TRANDAU td
group by td.SanVD
having count(td.MaTD) >= all (select count(td.MaTD)
								from TRANDAU td
								group by td.SanVD)
--Cau 4 Cho biết cầu thủ nào từng tham gia ở cả hai vị trí tiền đạo và tiền vệ
select distinct tg1.MaCT
from THAMGIA tg1 join THAMGIA tg2 on tg1.MaCT=tg2.MaCT
where tg1.Vitrithidau=N'tiền đạo' and tg2.Vitrithidau=N'tiền vệ'
--Cau 5 Cho biết đội nào đã thi đấu qua tất cả các sân vận động
--R:  MaDB, SanVD      
--S:  SanVD
--Ket qua: MaDB
select distinct db.MaDB
from DOIBONG db join TRANDAU td on db.MaDB=td.MaDoi1 or db.MaDB=td.MaDoi2
where not exists ( select SanVD from TRANDAU td2
					where SanVD not in (select SanVD from TRANDAU td3
										where db.MaDB=td3.MaDoi1 or db.MaDB=td3.MaDoi2))