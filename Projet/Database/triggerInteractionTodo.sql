CREATE TRIGGER insertinteractiontodo AFTER INSERT ON todo
BEGIN
	UPDATE lastinsert SET lastid = NEW.todoid WHERE name = "todoid";
END;
