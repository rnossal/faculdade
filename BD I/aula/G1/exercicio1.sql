create table TBCLIENTE(
    pkCodCLi integer not null,
    nomeCli varchar(25),
    endCli varchar(40),
    dataNascCli date,
    salarioCli number(15, 2),
    sexoCli varchar(1),
    constraint tbclientepk primary key(pkCodCLi)
);

insert into TBCLIENTE values(1, 'Maria Antonieta', 'Rua sei lá n 43', '20/08/2000', 1250.43, 'F');
insert into TBCLIENTE values(2, 'Bozo da Silva', 'Av do Carmo 20', '14/06/1990', 734.12, 'M');
insert into TBCLIENTE values(3, 'Fofão Machado', 'Rua aparecida 10', '07/03/1977', 2354.89, 'M');
insert into TBCLIENTE values(4, 'Pelé Rocha', 'Rua sei lá 222', '25/07/1978', 245.21, 'M');
insert into TBCLIENTE values(5, 'Faustão Domingos', 'AV do Carmo 171', '13/05/1988', 433.65, 'M');
insert into TBCLIENTE values(6, 'Xuxa Antibes', 'Rua Voando 33', '21/03/1950', 799.30, 'F');
insert into TBCLIENTE values(7, 'Caetano Velado', 'Rua Condor 50', '04/07/1990', 294.21, 'M');
insert into TBCLIENTE values(8, 'Beltrano Carlos', 'Av Brasil 501', '06/05/2001', 666.66, 'M');