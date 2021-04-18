/*
 * 有点小毛病不想改了
 * 模拟一个最不经常使用缓存策略
 */

import java.util.*;

class Node {
    public int count;
    public int key;
    public int value;
}

public class Main {
    public static void main(String[] args){
        Scanner scan = new Scanner(System.in);
        String com = scan.nextLine();
        String nu = scan.nextLine();
        com = com.replaceAll(" ", "");
        nu = nu.replaceAll(" ", "");

        String[] commands = com.split(",");
        String[] nums = nu.split("],");

        ArrayList<String> commandlist = new ArrayList<>(Arrays.asList(commands));
        ArrayList<String> numlist = new ArrayList<>(Arrays.asList(nums));
        numlist.set(numlist.size() - 1, numlist.get(numlist.size() - 1).replaceAll("]", ""));

        for (int i = 0; i < commandlist.size(); i++) {
            commandlist.set(i, commandlist.get(i).substring(1,  commandlist.get(i).length() - 1));
        }
        int count = 0;
        LinkedList<Node> linkedList = new LinkedList<>();

        ArrayList<String> arrayList = new ArrayList<>();
        for (int i = 0; i < commandlist.size(); i++) {
            if (commandlist.get(i).equals("LRUCache")) {
                count = Integer.parseInt(numlist.get(i).replaceAll("\\[",""));
                arrayList.add("null");
            }
            if (commandlist.get(i).equals("put")) {
                int a = Integer.parseInt(numlist.get(i).replaceAll("\\[", "").split(",")[0]);
                int b = Integer.parseInt(numlist.get(i).replaceAll("\\[", "").split(",")[1]);

                boolean flag = false;
                for (int j = 0; j < linkedList.size(); j++) {

                    Node node = new Node();
                    if (linkedList.get(j).key == a) {
                        linkedList.get(j).value = b;
                        linkedList.get(j).count++;

                        node = linkedList.get(j);
                        linkedList.remove(j);
                        flag = true;
                        break;
                    }

                    for (int k = 0; k < linkedList.size(); k++) {
                        if (linkedList.get(k).count == node.count)
                            linkedList.add(k, node);
                    }
                }

                if (!flag) {
                    if (linkedList.size() == count) {
                        linkedList.remove(linkedList.size() - 1);
                    }

                    for (int j = 0; j < linkedList.size(); j++) {
                        if (linkedList.get(j).count == 1) {
                            Node node = new Node();
                            node.key = a;
                            node.value = b;
                            node.count = 1;
                            linkedList.add(j, node);
                            break;
                        }
                    }
                    if (linkedList.size() == 0) {
                        Node node = new Node();
                        node.key = a;
                        node.value = b;
                        node.count = 1;
                        linkedList.add(node);
                    }


                }
                arrayList.add("null");
            }
            if (commandlist.get(i).equals("get")) {
                int a = Integer.parseInt(numlist.get(i).replaceAll("\\[", ""));
                boolean flag = false;
                for (int j = 0; j < linkedList.size(); j++) {
                    if (linkedList.get(j).key == a) {
                        arrayList.add(String.valueOf(linkedList.get(j).value));
                        linkedList.get(j).count++;
                        flag = true;
                        break;
                    }
                }
                if (!flag) {
                    arrayList.add("-1");
                }
            }
        }

        System.out.print("["+arrayList.get(0));
        for (int i = 1; i < arrayList.size(); i++) {
            System.out.print(", " + arrayList.get(i));
        }
        System.out.print("]");
    }
}