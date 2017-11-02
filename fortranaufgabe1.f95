subroutine showMatrix(array, s)
	integer, intent (in) :: s
    double precision, intent (in), dimension(s,s) :: array
    do i=1, s
    	do j=1, s
            print *, array(i,j)
		end do
    end do
end subroutine showMatrix

program multiplicate
	implicit none
	integer :: n, i ,j, k
    double precision, dimension(:,:),allocatable :: matrix1, matrix2, matrix3
   	integer ( kind = 4 ) mm, mm2, m, m2, s, s2
	integer values(8), values2(8)

	do n = 100, 2000, 100
		allocate(matrix1(n,n))
    	allocate(matrix2(n,n))
    	allocate(matrix3(n,n))
    
		do i = 1, n
    		do j= 1, n
        		matrix1(i,j) = 0.02*j
            	matrix2(i,j) = 0.01*j
            	matrix3(i,j) = 0
        	end do
    	end do
    
		call date_and_time(values = values)
		do i = 1, n
    		do j = 1, n
        		do k = 1, n
            		matrix3(i,j) = matrix1(i,k) * matrix2(k,j) + matrix3(i,j)
            	end do
        	end do
    	end do
    	call date_and_time(values = values2)
		m = values(6)
  		s = values(7)
  		mm = values(8)

	  	m2 = values2(6)
  		s2 = values2(7)
  		mm2 = values2(8)
	
    	write (*,*) 'diff minutes', m2 - m
    	write (*,*) 'diff seconds', s2 - s
    	write (*,*) 'diff milliseconds', mm2 - mm
    	deallocate(matrix1)
        deallocate(matrix2)
        deallocate(matrix3)
		!call showMatrix(matrix3, n)
	end do
end program multiplicate