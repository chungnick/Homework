syms cc;

nc=[-2, -0.5, -0.5, -0.5, -0.5; 
    -0.5, -2, -0.5, -0.5, -0.5; 
    -0.5, -0.5, -2, -0.5, -0.5; 
    -0.5, -0.5, -0.5, -2, -0.5; 
    -0.5, -0.5, -0.5, -0.5, -2];

a=[1;2;3;4;5];

b1=nc*a/norm(nc*a);
cc(1)=double(b1'*nc*b1)
b2=nc*b1/norm(nc*b1);
cc(2)=double(b2'*nc*b2)
b3=nc*b2/norm(nc*b2);
cc(3)=double(b3'*nc*b3)
b4=nc*b3/norm(nc*b3);
cc(4)=double(b4'*nc*b4)
b5=nc*b4/norm(nc*b4);
cc(5)=double(b5'*nc*b5)
b6=nc*b5/norm(nc*b5);
cc(6)=double(b6'*nc*b6)
b7=nc*b6/norm(nc*b6);
cc(7)=double(b7'*nc*b7)
b8=nc*b7/norm(nc*b7);
cc(8)=double(b8'*nc*b8)
b9=nc*b8/norm(nc*b8);
cc(9)=double(b9'*nc*b9)
b10=nc*b9/norm(nc*b9);
cc(10)=double(b10'*nc*b10)
b11=nc*b10/norm(nc*b10);
cc(11)=double(b11'*nc*b11)
b12=nc*b11/norm(nc*b11);
cc(12)=double(b12'*nc*b12)
b13=nc*b12/norm(nc*b12);
cc(13)=double(b13'*nc*b13)
b14=nc*b13/norm(nc*b13);
cc(14)=double(b14'*nc*b14)
b15=nc*b14/norm(nc*b14);
cc(15)=double(b15'*nc*b15)
b16=nc*b15/norm(nc*b15);
cc(16)=double(b16'*nc*b16)
b17=nc*b16/norm(nc*b16);
cc(17)=double(b17'*nc*b17)
b18=nc*b17/norm(nc*b17);
cc(18)=double(b18'*nc*b18)
b19=nc*b18/norm(nc*b18);
cc(19)=double(b19'*nc*b19)
b20=nc*b19/norm(nc*b19);
cc(20)=double(b20'*nc*b20)
b21=nc*b20/norm(nc*b20);
cc(21)=double(b21'*nc*b21)
b22=nc*b21/norm(nc*b21);
cc(22)=double(b22'*nc*b22)
b23=nc*b22/norm(nc*b22);
cc(23)=double(b23'*nc*b23)
b24=nc*b23/norm(nc*b23);
cc(24)=double(b24'*nc*b24)
b25=nc*b24/norm(nc*b24);
cc(25)=double(b25'*nc*b25)
b26=nc*b25/norm(nc*b25);
cc(26)=double(b26'*nc*b26)
b27=nc*b26/norm(nc*b26);
cc(27)=double(b27'*nc*b27)
b28=nc*b27/norm(nc*b27);
cc(28)=double(b28'*nc*b28)
b29=nc*b28/norm(nc*b28);
cc(29)=double(b29'*nc*b29)
b30=nc*b29/norm(nc*b29);
cc(30)=double(b30'*nc*b30)
b31=nc*b30/norm(nc*b30);
cc(31)=double(b31'*nc*b31)
b32=nc*b31/norm(nc*b31);
cc(32)=double(b32'*nc*b32)
b33=nc*b32/norm(nc*b32);
cc(33)=double(b33'*nc*b33)
b34=nc*b33/norm(nc*b33);
cc(34)=double(b34'*nc*b34)
b35=nc*b34/norm(nc*b34);
cc(35)=double(b35'*nc*b35)
b36=nc*b35/norm(nc*b35);
cc(36)=double(b36'*nc*b36)
b37=nc*b36/norm(nc*b36);
cc(37)=double(b37'*nc*b37)
b38=nc*b37/norm(nc*b37);
cc(38)=double(b38'*nc*b38)
b39=nc*b38/norm(nc*b38);
cc(39)=double(b39'*nc*b39)
b40=nc*b39/norm(nc*b39);
cc(40)=double(b40'*nc*b40)
b41=nc*b40/norm(nc*b40);
cc(41)=double(b41'*nc*b41)
b42=nc*b41/norm(nc*b41);
cc(42)=double(b42'*nc*b42)
b43=nc*b42/norm(nc*b42);
cc(43)=double(b43'*nc*b43)
b44=nc*b43/norm(nc*b43);
cc(44)=double(b44'*nc*b44)
b45=nc*b44/norm(nc*b44);
cc(45)=double(b45'*nc*b45)
b46=nc*b45/norm(nc*b45);
cc(46)=double(b46'*nc*b46)
b47=nc*b46/norm(nc*b46);
cc(47)=double(b47'*nc*b47)
b48=nc*b47/norm(nc*b47);
cc(48)=double(b48'*nc*b48)
b49=nc*b48/norm(nc*b48);
cc(49)=double(b49'*nc*b49)
b50=nc*b49/norm(nc*b49);
cc(50)=double(b50'*nc*b50)
b51=nc*b50/norm(nc*b50);
cc(51)=double(b51'*nc*b51)
b52=nc*b51/norm(nc*b51);
cc(52)=double(b52'*nc*b52)
b53=nc*b52/norm(nc*b52);
cc(53)=double(b53'*nc*b53)
b54=nc*b53/norm(nc*b53);
cc(54)=double(b54'*nc*b54)
b55=nc*b54/norm(nc*b54);
cc(55)=double(b55'*nc*b55)
b56=nc*b55/norm(nc*b55);
cc(56)=double(b56'*nc*b56)
b57=nc*b56/norm(nc*b56);
cc(57)=double(b57'*nc*b57)
b58=nc*b57/norm(nc*b57);
cc(58)=double(b58'*nc*b58)
b59=nc*b58/norm(nc*b58);
cc(59)=double(b59'*nc*b59)
b60=nc*b59/norm(nc*b59);
cc(60)=double(b60'*nc*b60)
b61=nc*b60/norm(nc*b60);
cc(61)=double(b61'*nc*b61)
b62=nc*b61/norm(nc*b61);
cc(62)=double(b62'*nc*b62)
b63=nc*b62/norm(nc*b62);
cc(63)=double(b63'*nc*b63)
b64=nc*b63/norm(nc*b63);
cc(64)=double(b64'*nc*b64)
b65=nc*b64/norm(nc*b64);
cc(65)=double(b65'*nc*b65)
b66=nc*b65/norm(nc*b65);
cc(66)=double(b66'*nc*b66)
b67=nc*b66/norm(nc*b66);
cc(67)=double(b67'*nc*b67)
b68=nc*b67/norm(nc*b67);
cc(68)=double(b68'*nc*b68)
b69=nc*b68/norm(nc*b68);
cc(69)=double(b69'*nc*b69)
b70=nc*b69/norm(nc*b69);
cc(70)=double(b70'*nc*b70)
b71=nc*b70/norm(nc*b70);
cc(71)=double(b71'*nc*b71)
b72=nc*b71/norm(nc*b71);
cc(72)=double(b72'*nc*b72)
b73=nc*b72/norm(nc*b72);
cc(73)=double(b73'*nc*b73)
b74=nc*b73/norm(nc*b73);
cc(74)=double(b74'*nc*b74)
b75=nc*b74/norm(nc*b74);
cc(75)=double(b75'*nc*b75)
b76=nc*b75/norm(nc*b75);
cc(76)=double(b76'*nc*b76)
b77=nc*b76/norm(nc*b76);
cc(77)=double(b77'*nc*b77)
b78=nc*b77/norm(nc*b77);
cc(78)=double(b78'*nc*b78)
b79=nc*b78/norm(nc*b78);
cc(79)=double(b79'*nc*b79)
b80=nc*b79/norm(nc*b79);
cc(80)=double(b80'*nc*b80)
b81=nc*b80/norm(nc*b80);
cc(81)=double(b81'*nc*b81)
b82=nc*b81/norm(nc*b81);
cc(82)=double(b82'*nc*b82)
b83=nc*b82/norm(nc*b82);
cc(83)=double(b83'*nc*b83)
b84=nc*b83/norm(nc*b83);
cc(84)=double(b84'*nc*b84)
b85=nc*b84/norm(nc*b84);
cc(85)=double(b85'*nc*b85)
b86=nc*b85/norm(nc*b85);
cc(86)=double(b86'*nc*b86)
b87=nc*b86/norm(nc*b86);
cc(87)=double(b87'*nc*b87)
b88=nc*b87/norm(nc*b87);
cc(88)=double(b88'*nc*b88)
b89=nc*b88/norm(nc*b88);
cc(89)=double(b89'*nc*b89)
b90=nc*b89/norm(nc*b89);
cc(90)=double(b90'*nc*b90)
b91=nc*b90/norm(nc*b90);
cc(91)=double(b91'*nc*b91)
b92=nc*b91/norm(nc*b91);
cc(92)=double(b92'*nc*b92)
b93=nc*b92/norm(nc*b92);
cc(93)=double(b93'*nc*b93)
b94=nc*b93/norm(nc*b93);
cc(94)=double(b94'*nc*b94)
b95=nc*b94/norm(nc*b94);
cc(95)=double(b95'*nc*b95)
b96=nc*b95/norm(nc*b95);
cc(96)=double(b96'*nc*b96)
b97=nc*b96/norm(nc*b96);
cc(97)=double(b97'*nc*b97)
b98=nc*b97/norm(nc*b97);
cc(98)=double(b98'*nc*b98)
b99=nc*b98/norm(nc*b98);
cc(99)=double(b99'*nc*b99)
b100=nc*b99/norm(nc*b99);
cc(100)=double(b100'*nc*b100)

b100'*nc*b100
% largest eigenvalue comes out equal to -4

eig(nc)
% equals -4

plot(cc)
