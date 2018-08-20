# Cria tabela cidade.
create table tbcidade(
	pkcodcid integer not null,
	nodemid varchar(20) not null,
	ufcid varchar(2),
	primary key(pkcodcid)
);

# Cria tabela cliente.
create table tbcliente(
	pkcodcli integer not null,
	nomecli varchar(20) not null,
	datanasccli date,
	salariocli number(15, 2) default 0,
	fkcodcid integer,
	constraint tbclientepk primary key(pkcodcli)
);

#Mostra estrutura da tabela.
describe tbcliente

# Adiciona a coluna email.
alter table tbcliente
	add email varchar(60);

# Altera nome da coluna.
alter table tbcliente
	rename column email to emailcli;

# Altera o tipo de dado da coluna.
alter table tbcliente
	modify emailcli varchar(100);

# Remove a coluna da tablela
alter table tbcliente
	drop column emailcli;

# Adiciona primary key.
alter table tbcliente
	add constraint tbclientpk primary key(pkcodcli);

# Adiciona a chave estrangeira.
alter table tbcliente
	add constraint tbcliente_fkcodcid foreign key(fkcodcid) references tbcidade(pkcodcid);