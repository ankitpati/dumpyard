-- Messpoll

create table pollinfo(
    sl int unsigned primary key not null auto_increment,
    curtime int unsigned not null,
    rmtaddr varchar(50) not null,
    breakfast char(2) not null,
    lunch char(2) not null,
    dinner char(2) not null
) engine=myisam;

create table votedMenue(
    day smallint unsigned primary key not null auto_increment,
    breakfast varchar(100) not null,
    lunch varchar(100) not null,
    snacks varchar(100) not null,
    dinner varchar(100) not null
) engine=myisam;

create table voteRecord(
    prn bigint unsigned not null,
    weekday tinyint unsigned not null,
    meal tinyint unsigned not null,
    vote varchar(100) not null,
    primary key(prn, weekday, meal)
) engine=myisam;

create table users(
    username varchar(100) primary key not null,
    password varchar(100) not null
) engine=myisam;

create table logins(
    sl integer unsigned primary key not null auto_increment,
    date_time datetime not null,
    ip_address varchar(50) not null,
    username varchar(100) not null
) engine=myisam;


-- CodeRush

create table submit(
    username varchar(256) not null,
    level tinyint unsigned not null,
    ques tinyint unsigned not null,
    ans varchar(512) not null,
    curtime datetime not null,
    primary key(username, level, ques)
) engine=myisam;

create table users(
    username varchar(256) primary key not null,
    password varchar(100) not null,
    admin tinyint unsigned not null
) engine=myisam;


-- PyJudge

create table submit(
    username varchar(256) not null,
    level tinyint unsigned not null,
    ques tinyint unsigned not null,
    filename varchar(256) not null,
    language varchar(5) not null,
    ans blob not null,
    curtime datetime not null,
    primary key(username, level, ques)
) engine=myisam;

create table users(
    username varchar(256) primary key not null,
    password varchar(100) not null,
    admin tinyint unsigned not null
) engine=myisam;


-- TnP

create table company(
    sl integer unsigned primary key not null auto_increment,
    name varchar(100) not null,
    contact varchar(100) not null,
    email varchar(256),
    phone varchar(20),
    follup date,
    internship varchar(3),
    hiring varchar(3)
) engine=myisam;

create table users(
    username varchar(100) primary key not null,
    password varchar(100) not null
) engine=myisam;


-- ImageDB

create table images(
    sl integer unsigned primary key not null auto_increment,
    name varchar(100) not null,
    image longblob not null
) engine=myisam;


-- JHotelMgmt

create table users(
    username varchar(256) primary key not null,
    password varchar(100) not null,
    admin tinyint unsigned not null
) engine=InnoDB;

create table hotels(
    hotel varchar(256) primary key not null,
    rooms integer not null
) engine=InnoDB;

create table guests(
    name varchar(256) not null,
    hotel varchar(256) not null,
    roomtype varchar(100) not null,

    primary key (name, hotel),

    foreign key (hotel)
        references hotels(hotel)
        on delete cascade
) engine=InnoDB;

create table services(
    name varchar(256) not null,
    hotel varchar(256) not null,
    service varchar(256) not null,
    cost integer unsigned not null,

    foreign key (name, hotel)
        references guests(name, hotel)
        on delete cascade
) engine=InnoDB;

-- Product Management

create table product (
    id int unsigned primary key not null,
    name char(100) not null,
    description char(100) not null,
    date date not null,
    quantity int unsigned not null,
    rate int unsigned not null
);

-- Registration Servlet

create table registered_users (
    id int unsigned primary key not null auto_increment,
    name char(100) not null,
    password char(100) not null,
    email char(100) not null,
    country char(100) not null
);
