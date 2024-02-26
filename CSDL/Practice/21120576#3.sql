-- Q1. Cho biết họ tên và mức lương của các giáo viên nữ.
select hoten, luong
from GIAOVIEN
where phai = N'Nữ'

-- Q2. Cho biết họ tên của các giáo viên và lương của họ sau khi tăng 10%
select hoten, (luong * 1.1) as luong_tang_10
from GIAOVIEN
where phai = N'Nữ'

-- Q3. Cho biết mã của các giáo viên có họ tên bắt đầu là "Nguyễn"
-- và lương trên $2000 hoặc, giáo viên là trưởng bộ môn nhận chức sau 1995.
select magv, hoten
from GIAOVIEN
where (hoten LIKE N'Nguyễn%' and luong > 2000.0)
or magv IN (select truongbm from BOMON where YEAR(ngaychanchuc) > 1995)

-- Q4 Cho biết tên những giáo viên khoa Công nghệ thông tin.
select hoten
from GIAOVIEN
where mabm IN (select bm.mabm from KHOA k join BOMON bm
              on k.makhoa = bm.makhoa where k.makhoa = 'CNTT')
              
-- Q5 Cho biết thông tin của bộ môn cùng thông tin giảng viên
-- làm trưởng bộ môn đó
select *
from BOMON bm join GIAOVIEN gv on bm.truongbm = gv.magv

-- Q6 Với mỗi giáo viên, hãy cho biết thông tin của bộ môn mà họ đang làm việc
select *
from BOMON bm join GIAOVIEN gv on bm.mabm = gv.mabm

-- Q7 Cho biết tên đề tài và giáo viên chủ nhiệm đề tài
select tendt, hoten
from GIAOVIEN gv join THAMGIADT tgdt on gv.magv = tgdt.magv
join DETAI dt on tgdt.madt = dt.madt
where gv.magv = dt.gvcndt

-- Q8 Với mỗi khoa cho biết thông tin trưởng khoa
select magv, hoten, luong, phai, ngsinh, diachi, gvqlcm, mabm
from GIAOVIEN gv join KHOA k on k.truongkhoa = gv.magv

-- Q9 Cho biết các giáo viên của bộ môn "Vi sinh" có tham gia đề tài 006
select *
from GIAOVIEN
where mabm = 'VS' and magv IN (select magv from THAMGIADT where madt = '006')

-- Q10 Với những đề tài thuộc cấp quản lí "Thành phố", cho biết mã đề 
-- tài, đề tài thuộc về chủ đề nào, họ tên người chủ nhiệm đề tài cùng Với
-- ngày sinh và địa chỉ của người ấy.
select madt, macd, hoten, ngsinh, diachi
from DETAI dt join GIAOVIEN gv on dt.gvcndt = gv.magv
where dt.capql = N'Thành phố'

-- Q11 Tìm họ tên của từng giáo viên và người phụ trách chuyên môn trực tiếp
-- của giáo viên đó
select gv.hoten, phutrach.hoten
from GIAOVIEN gv join GIAOVIEN phutrach on gv.magv = phutrach.gvqlcm

-- Q12 Tìm họ tên của những giáo viên được "Nguyễn Thanh Tùng"
-- phụ trách trực tiếp
select hoten
from GIAOVIEN
where gvqlcm = (select magv from GIAOVIEN where hoten = N'Nguyễn Thanh Tùng')

-- Q13 Cho biết tên giáo viên là trưởng bộ môn "Hệ thống thông tin"

select hoten
from GIAOVIEN gv join BOMON bm on gv.mabm = bm.mabm
where bm.tenbm = N'Hệ thống thông tin'

--- Q14 Cho biết tên người chủ nhiệm đề tài của những đề tài thuộc chủ đề
-- Quản lý giáo dục
select hoten
from GIAOVIEN gv join DETAI dt on dt.gvcndt = gv.magv
where dt.macd = (select macd from CHUDE where tencd = N'Quản lý giáo dục')

-- Q15 Cho biết tên các công việc của đề tài HTTT quản lý các trường ĐH có thời
-- gian bắt đầu trong tháng 3/2008
select tencv
from CONGVIEC cv join DETAI dt on dt.madt = cv.madt
where tendt = N'HTTT quản lý các trường ĐH' and (ngaybd >= '2008-03-01' and ngaybd <=  '2008-03-31')

-- Q16 Cho biết tên giáo viên và tên người quản lý chuyên môn của giáo viên đó.
select gv.hoten, phutrach.hoten
from GIAOVIEN gv join GIAOVIEN phutrach on gv.magv = phutrach.gvqlcm

-- Q17 Cho các công việc bắt đầu trong khoảng từ 01/01/2007 đến 01/08/2007
select *
from CONGVIEC
where ngaybd between '01/01/2007' and '01/08/2007'

-- Q18 Cho biết họ tên các giáo viên cùng bộ môn với giáo viên
-- "Trần Trà Hương"
select hoten
from GIAOVIEN
where mabm = (select mabm from GIAOVIEN where hoten = N'Trần Trà Hương')
except
select hoten from GIAOVIEN where hoten = N'Trần Trà Hương'

-- Q19 Tìm những giáo viên vừa là trưởng bộ môn vừa chủ nhiệm đề tài
select *
from GIAOVIEN
where magv IN (select truongbm from BOMON) and magv IN (select gvcndt from DETAI)

-- Q20 Cho biết tên những giáo viên vừa chủ nhiệm đề tài
select hoten
from GIAOVIEN
where magv IN (select truongbm from BOMON) and magv IN (select truongkhoa from KHOA)

-- Q21 Cho biết tên những trưởng bộ môn mà vừa chủ nhiệm đề tài
select hoten
from GIAOVIEN
where magv IN (select truongbm from BOMON) and magv IN (select gvcndt from DETAI)

-- Q22 Cho biết mã số các trưởng khoa có chủ nhiệm đề tài
select magv
from GIAOVIEN
where magv IN (select gvcndt from DETAI) and magv IN (select truongkhoa from KHOA)

-- Q23 Cho biết mã số các giáo viên thuộc bộ môn "HTTT" hoặc có tham gia đề tài mã "001"
select gv.magv
from GIAOVIEN gv join THAMGIADT tgdt on gv.magv = tgdt.magv
where gv.mabm = N'HTTT' or tgdt.madt = '001'

-- Q24 Cho biết giáo viên làm việc cùng bộ môn với giáo viên 002
select *
from GIAOVIEN
where mabm = (select mabm from GIAOVIEN where magv = '002')

-- Q25 Tìm những giáo viên là trưởng bộ môn
select *
from GIAOVIEN gv join BOMON bm on gv.mabm = bm.mabm
where gv.magv = bm.truongbm

-- Q26 Cho biết họ tên và mức lương của các giáo viên
select hoten, luong
from GIAOVIEN

-- Q27 Cho biết số lượng giáo viên viên và tổng lương của họ.
select count(magv), sum(luong)
from GIAOVIEN

-- Q28 Cho biết số lượng giáo viên và lương trung bình của từng bộ môn.
select count(magv), AVG(luong)
from GIAOVIEN
group by mabm

-- Q29 Cho biết tên chủ đề và số lượng đề tài thuộc về chủ đề đó.
select tencd, count(madt)
from CHUDE cd left join DETAI dt on cd.macd = dt.macd
group by cd.macd, tencd

-- Q30 Cho biết tên giáo viên và số lượng đề tài mà giáo viên đó tham gia.
select hoten, count(distinct madt)
from GIAOVIEN gv left join THAMGIADT tgdt on gv.magv = tgdt.magv
group by gv.magv, gv.hoten

-- Q31 Cho biết tên giáo viên và số lượng đề tài mà giáo viên đó làm chủ nhiệm.
select hoten, count(madt)
from GIAOVIEN gv join DETAI dt on gv.magv = dt.gvcndt
group by gv.magv, gv.hoten

-- Q32 Với mỗi giáo viên cho tên giáo viên và số người thân của giáo viên đó.
select gv.hoten, count(tennt)
from GIAOVIEN gv join NGUOITHAN nt on gv.magv = nt.magv
group by gv.magv, gv.hoten

-- Q33 Cho biết tên những giáo viên đã tham gia từ 3 đề tài trở lên.
select gv.hoten, count(distinct madt)
from GIAOVIEN gv join THAMGIADT tgdt on gv.magv = tgdt.magv
group by gv.magv, gv.hoten
having count(madt) > 3

-- Q34 Cho biet so luong giao vien da tham gia vao de tai Ung dung hoa hoc xanh
select count(tgdt.magv)
from THAMGIADT tgdt join DETAI dt on tgdt.madt = dt.madt
where dt.tendt = N'Ứng dụng hóa học xanh'
group by dt.tendt